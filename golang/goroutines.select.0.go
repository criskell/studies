package main

import (
	"fmt"
	"time"
	"math/rand"
)

func task(name string, delay time.Duration, channel chan string) {
	time.Sleep(delay)
	channel <- fmt.Sprintf("%s terminou após %v", name, delay)
}

func main() {
	rand.Seed(time.Now().UnixNano())

	ch1 := make(chan string)
	ch2 := make(chan string)

	go task("task 1", time.Duration(rand.Intn(3) + 1) * time.Second, ch1)
	go task("task 2", time.Duration(rand.Intn(3) + 1) * time.Second, ch2)

	select {
	case msg1 := <-ch1:
		fmt.Println("channel 1: ", msg1)
	case msg2 := <-ch2:
		fmt.Println("channel 2: ", msg2)
	}
}
