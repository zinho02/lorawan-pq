#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "api.h" // NIST PQC API: provides crypto_sign_keypair, crypto_sign, crypto_sign_open

#define ITERATIONS 10000
#define MESSAGE_LEN 32

int interrupt_mode = 0; // Global flag to control interrupt behavior

// Timing helper
double time_diff_ns(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
}

// Benchmark result
typedef struct {
    double avg;
    double stddev;
} stats_t;

void wait_for_continue(const char *op_name) {
    if (interrupt_mode) {
        char input[10];
        printf("\n[Interrupt] Ready to perform %s. Type 'c' to continue: ", op_name);
        fflush(stdout);
        while (1) {
            fgets(input, sizeof(input), stdin);
            if (input[0] == 'c' || input[0] == 'C') break;
            printf("Invalid input. Type 'c' to continue: ");
        }
    }
}

stats_t benchmark_operation(void (*operation)(void), int iterations, const char *op_name) {
    double *times = malloc(iterations * sizeof(double));
    struct timespec start, end;

    for (int i = 0; i < iterations; i++) {
        wait_for_continue(op_name);
        clock_gettime(CLOCK_MONOTONIC, &start);
        operation();
        clock_gettime(CLOCK_MONOTONIC, &end);
        times[i] = time_diff_ns(start, end);
    }

    double sum = 0;
    for (int i = 0; i < iterations; i++) sum += times[i];
    double mean = sum / iterations;

    double variance = 0;
    for (int i = 0; i < iterations; i++)
        variance += pow(times[i] - mean, 2);
    variance /= iterations;
    double stddev = sqrt(variance);

    free(times);
    return (stats_t){ mean / 1e6, stddev / 1e6 }; // Return in ms
}

// Wrappers for NIST API functions
unsigned char pk[CRYPTO_PUBLICKEYBYTES];
unsigned char sk[CRYPTO_SECRETKEYBYTES];
unsigned char msg[MESSAGE_LEN];
unsigned char signed_msg[MESSAGE_LEN + CRYPTO_BYTES];
unsigned long long signed_len;
unsigned char unsigned_msg[MESSAGE_LEN + CRYPTO_BYTES];
unsigned long long unsigned_len;

void op_keygen(void) {
    crypto_sign_keypair(pk, sk);
}

void op_sign(void) {
    crypto_sign(signed_msg, &signed_len, msg, MESSAGE_LEN, sk);
}

void op_verify(void) {
    crypto_sign_open(unsigned_msg, &unsigned_len, signed_msg, signed_len, pk);
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "interrupt") == 0) {
        interrupt_mode = 1;
        printf("[Mode] Interrupt mode enabled.\n");
    }

    printf("Benchmarking NIST PQC Signature Scheme: %s\n", CRYPTO_ALGNAME);
    memset(msg, 0xA5, sizeof(msg)); // Sample fixed message

    crypto_sign_keypair(pk, sk);
    crypto_sign(signed_msg, &signed_len, msg, MESSAGE_LEN, sk);
    crypto_sign_open(unsigned_msg, &unsigned_len, signed_msg, signed_len, pk);

    stats_t keygen_stats = benchmark_operation(op_keygen, ITERATIONS, "Key Generation");
    stats_t sign_stats = benchmark_operation(op_sign, ITERATIONS, "Signing");
    stats_t verify_stats = benchmark_operation(op_verify, ITERATIONS, "Verification");

    printf("\nResults over %d iterations:\n", ITERATIONS);
    printf("Key Generation:   Avg = %.3f ms, StdDev = %.3f ms\n", keygen_stats.avg, keygen_stats.stddev);
    printf("Signing:          Avg = %.3f ms, StdDev = %.3f ms\n", sign_stats.avg, sign_stats.stddev);
    printf("Verification:     Avg = %.3f ms, StdDev = %.3f ms\n", verify_stats.avg, verify_stats.stddev);

    return 0;
}
