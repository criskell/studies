package main

import (
	"fmt"
	"math"
)

func Sqrt(x float64) float64 {
	currentGuess := 1.0
	previousGuess := currentGuess

	for {
		previousGuess = currentGuess
		
		// New estimative is `currentGuess - f(x) / f'(x)`.
		// where `f(x) = currentGuess**2 - currentGuess` and f'(x) is derivative of `f` at `x`.
		currentGuess -=  (math.Pow(currentGuess, 2) - x) / (2 * currentGuess)
	
		// 1e-15 is the precision of float64.
		if math.Abs(currentGuess - previousGuess) < 1e-15  {
			break
		}
	}
	
	return currentGuess
}

func main() {
	fmt.Println(Sqrt(16))
	fmt.Println(Sqrt(2))
}
