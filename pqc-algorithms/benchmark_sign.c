#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "api.h" // NIST PQC API: provides crypto_sign_keypair, crypto_sign, crypto_sign_open

#define ITERATIONS 10000
#define MESSAGE_LEN 32

int interrupt_mode = 0; // Global flag for interrupt mode

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

stats_t benchmark_combined(int iterations) {
    double *keygen_times = malloc(iterations * sizeof(double));
    double *sign_times = malloc(iterations * sizeof(double));
    double *verify_times = malloc(iterations * sizeof(double));

    unsigned char msg[MESSAGE_LEN];
    memset(msg, 0xA5, sizeof(msg)); // Fixed message

    for (int i = 0; i < iterations; i++) {
        unsigned char pk[CRYPTO_PUBLICKEYBYTES];
        unsigned char sk[CRYPTO_SECRETKEYBYTES];
        unsigned char signed_msg[MESSAGE_LEN + CRYPTO_BYTES];
        unsigned long long signed_len;
        unsigned char unsigned_msg[MESSAGE_LEN + CRYPTO_BYTES];
        unsigned long long unsigned_len;

        struct timespec start, end;

        // Keygen
        wait_for_continue("Key Generation");
        clock_gettime(CLOCK_MONOTONIC, &start);
        crypto_sign_keypair(pk, sk);
        clock_gettime(CLOCK_MONOTONIC, &end);
        keygen_times[i] = time_diff_ns(start, end);

        // Sign
        wait_for_continue("Signing");
        clock_gettime(CLOCK_MONOTONIC, &start);
        crypto_sign(signed_msg, &signed_len, msg, MESSAGE_LEN, sk);
        clock_gettime(CLOCK_MONOTONIC, &end);
        sign_times[i] = time_diff_ns(start, end);

        // Verify
        wait_for_continue("Verification");
        clock_gettime(CLOCK_MONOTONIC, &start);
        crypto_sign_open(unsigned_msg, &unsigned_len, signed_msg, signed_len, pk);
        clock_gettime(CLOCK_MONOTONIC, &end);
        verify_times[i] = time_diff_ns(start, end);
    }

    // Helper lambda for average and stddev
    auto compute_stats = [](double *times, int count) -> stats_t {
        double sum = 0;
        for (int i = 0; i < count; i++) sum += times[i];
        double mean = sum / count;

        double variance = 0;
        for (int i = 0; i < count; i++) variance += pow(times[i] - mean, 2);
        variance /= count;

        return (stats_t){ mean / 1e6, sqrt(variance) / 1e6 }; // in ms
    };

    stats_t keygen_stats = compute_stats(keygen_times, iterations);
    stats_t sign_stats = compute_stats(sign_times, iterations);
    stats_t verify_stats = compute_stats(verify_times, iterations);

    free(keygen_times);
    free(sign_times);
    free(verify_times);

    printf("\nResults over %d iterations:\n", iterations);
    printf("Key Generation:   Avg = %.3f ms, StdDev = %.3f ms\n", keygen_stats.avg, keygen_stats.stddev);
    printf("Signing:          Avg = %.3f ms, StdDev = %.3f ms\n", sign_stats.avg, sign_stats.stddev);
    printf("Verification:     Avg = %.3f ms, StdDev = %.3f ms\n", verify_stats.avg, verify_stats.stddev);

    return keygen_stats; // Just to satisfy return type, not used
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "interrupt") == 0) {
        interrupt_mode = 1;
        printf("[Mode] Interrupt mode enabled.\n");
    }

    printf("Benchmarking NIST PQC Signature Scheme: %s\n", CRYPTO_ALGNAME);
    benchmark_combined(ITERATIONS);
    return 0;
}

