package main

import (
	"fmt"
	"time"
)

func sendMessage(name string, delay time.Duration, channel chan string) {
	time.Sleep(delay)
	channel <- fmt.Sprintf("Mensagem de %s (após %v)", name, delay)
}

func main() {
	channel := make(chan string)

	go sendMessage("criskell", 2*time.Second, channel)
	go sendMessage("maria", 1*time.Second, channel)

	for i := 0; i < 2; i++ {
		msg := <-channel
		fmt.Println("Recebido: ", msg)
	}
}
