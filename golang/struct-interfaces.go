package main

import (
	"fmt"
)

type Dog struct{}
func (d Dog) Speak() string { return "Au au" }

type Cat struct{}
func (c Cat) Speak() string { return "Miau!" }

// Não há necessidade de um subtipo declarar explicitamente que implementa a interface.
type Animal interface {
	Speak() string
}

func listen(a Animal) {
	fmt.Println(a.Speak())
}

func main() {
	dog := Dog{}
	cat := Cat{}

	listen(dog)
	listen(cat)
}
