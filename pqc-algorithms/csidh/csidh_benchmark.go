package main

import (
	"bufio"
	"crypto/rand"
	"fmt"
	"math"
	"os"
	"time"

	"github.com/cloudflare/circl/dh/csidh"
)

const iterations = 10000

var out [64]byte
var rng = rand.Reader
var interruptMode = false

func main() {
	if len(os.Args) > 1 && os.Args[1] == "interrupt" {
		interruptMode = true
	}

	var keygenTimes, pubkeyTimes, sharedTimes []float64

	for i := 0; i < iterations; i++ {
		if interruptMode {
			waitForContinue("Press 'c' to continue to Key Generation")
		}
		start := time.Now()
		priv := csidh.PrivateKey{}
		csidh.GeneratePrivateKey(&priv, rng)
		elapsed := time.Since(start).Seconds() * 1000
		keygenTimes = append(keygenTimes, elapsed)

		if interruptMode {
			waitForContinue("Press 'c' to continue to Public Key Computation")
		}
		start = time.Now()
		pub := csidh.PublicKey{}
		csidh.GeneratePublicKey(&pub, &priv, rng)
		elapsed = time.Since(start).Seconds() * 1000
		pubkeyTimes = append(pubkeyTimes, elapsed)

		if interruptMode {
			waitForContinue("Press 'c' to continue to Shared Secret Derivation")
		}
		priv2 := csidh.PrivateKey{}
		csidh.GeneratePrivateKey(&priv2, rng)
		pub2 := csidh.PublicKey{}
		csidh.GeneratePublicKey(&pub2, &priv2, rng)

		start = time.Now()
		csidh.DeriveSecret(&out, &pub, &priv2, rng)
		elapsed = time.Since(start).Seconds() * 1000
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

func waitForContinue(prompt string) {
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Println(prompt)
		input, _ := reader.ReadString('\n')
		if input == "c\n" || input == "c\r\n" {
			break
		}
	}
}

