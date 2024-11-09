package main

import (
    "fmt"
    "log"
    "example.com/greetings"
)

func main() {
    log.SetPrefix("greetings: ")
    // Disable printing time, source file, and line number.
    log.SetFlags(0)

    message, err := greetings.Hello("")
    fmt.Println(message)

    if err != nil {
        log.Fatal(err)
    }

    fmt.Println(message)
}
