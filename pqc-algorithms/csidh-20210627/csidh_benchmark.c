#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <assert.h>

#include "fp.h"
#include "csidh.h"

#define ITERATIONS 10000

static double times_keygen[ITERATIONS];
static double times_pubkey[ITERATIONS];
static double times_shared[ITERATIONS];

static int interrupt_mode = 0;

static void record_time(double *arr, int idx, clock_t start, clock_t end) {
    arr[idx] = 1000.0 * (end - start) / CLOCKS_PER_SEC;
}

static void print_stats(const char *label, double *arr, int n) {
    double sum = 0, mean = 0, stddev = 0;

    for (int i = 0; i < n; ++i)
        sum += arr[i];
    mean = sum / n;

    for (int i = 0; i < n; ++i)
        stddev += (arr[i] - mean) * (arr[i] - mean);
    stddev = sqrt(stddev / n);

    printf("%s:\n", label);
    printf("  Average Time: %.3f ms\n", mean);
    printf("  Std Dev:      %.3f ms\n\n", stddev);
}

static void wait_for_continue(const char *msg) {
    if (!interrupt_mode) return;
    printf("%s\n", msg);
    fflush(stdout);

    int c;
    do {
        c = getchar();
    } while (c != 'c' && c != 'C');
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "interrupt") == 0) {
        interrupt_mode = 1;
    }

    private_key priv1, priv2;
    public_key pub1, pub2, shared;

    for (int i = 0; i < ITERATIONS; ++i) {
        clock_t start, end;

        wait_for_continue("Press 'c' to continue to Key Generation");
        start = clock();
        csidh_private(&priv1);
        end = clock();
        record_time(times_keygen, i, start, end);

        wait_for_continue("Press 'c' to continue to Public Key Computation");
        start = clock();
        csidh(&pub1, &base, &priv1);
        assert(ret);
        end = clock();
        record_time(times_pubkey, i, start, end);

        csidh_private(&priv2);
        csidh(&pub2, &base, &priv2);
        assert(ret);

        wait_for_continue("Press 'c' to continue to Shared Secret Derivation");
        start = clock();
        csidh(&shared, &pub1, &priv2);
        assert(ret);
        end = clock();
        record_time(times_shared, i, start, end);
    }

    print_stats("Key Generation", times_keygen, ITERATIONS);
    print_stats("Public Key Computation", times_pubkey, ITERATIONS);
    print_stats("Shared Secret Derivation", times_shared, ITERATIONS);

    return 0;
}

