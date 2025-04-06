package main

import (
	"fmt"
)

func typeInfo(v interface{}) {
	switch t := v.(type) {
	case string:
		fmt.Println("É uma string: ", t)
	case int:
		fmt.Println("É um inteiro: ", t)
	case bool:
		fmt.Println("É um booleano: ", t)
	default:
		fmt.Println("Tipo desconhecido")
	}
}

func main() {
	fmt.Println("Hello")

	var x interface{} // contém qualquer valor.

	x = 50
	x = "Oi"

	s, ok := x.(string)

	if ok {
		fmt.Println("É uma string! O valor dela: ", s)
	}

	x = 42

	i, ok := x.(int)
	
	if ok {
		fmt.Println("É um inteiro! O valor do inteiro: ", i)
	}

	x = false

	typeInfo(x)
}
