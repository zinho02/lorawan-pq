package main

import (
	"crypto/rand"
	"fmt"
	"math"
	"time"

	"github.com/cloudflare/circl/dh/csidh"
)

const iterations = 10000
var out[64] byte
var rng = rand.Reader

func main() {
	var keygenTimes, pubkeyTimes, sharedTimes []float64

	for i := 0; i < iterations; i++ {
		// Key generation
		start := time.Now()
		priv := csidh.PrivateKey{}
		csidh.GeneratePrivateKey(&priv, rng)
		elapsed := time.Since(start).Seconds() * 1000 // ms
		keygenTimes = append(keygenTimes, elapsed)

		// Public key computation
		start = time.Now()
		pub := csidh.PublicKey{}
		csidh.GeneratePublicKey(&pub, &priv, rng)
		elapsed = time.Since(start).Seconds() * 1000 // ms
		pubkeyTimes = append(pubkeyTimes, elapsed)

		// Shared secret computation with a second key
		priv2 := csidh.PrivateKey{}
		csidh.GeneratePrivateKey(&priv2, rng)
		pub2 := csidh.PublicKey{}
		csidh.GeneratePublicKey(&pub2, &priv2, rng)

		start = time.Now()
		csidh.DeriveSecret(&out, &pub, &priv2, rng)
		elapsed = time.Since(start).Seconds() * 1000 // ms
		sharedTimes = append(sharedTimes, elapsed)
	}

	printStats("Key Generation", keygenTimes)
	printStats("Public Key Computation", pubkeyTimes)
	printStats("Shared Secret Derivation", sharedTimes)
}

func printStats(name string, times []float64) {
	sum := 0.0
	for _, t := range times {
		sum += t
	}
	mean := sum / float64(len(times))

	variance := 0.0
	for _, t := range times {
		variance += math.Pow(t-mean, 2)
	}
	stddev := math.Sqrt(variance / float64(len(times)))

	fmt.Printf("%s:\n", name)
	fmt.Printf("  Average Time: %.3f ms\n", mean)
	fmt.Printf("  Std Dev:      %.3f ms\n\n", stddev)
}

