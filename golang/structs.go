package main

import (
	"fmt"
	"encoding/json"
)

type Person struct {
	Name string `json:"id"`
	Age int `json:"name"`
}

type Address struct {
	City string
}

type Employee struct {
	Name string
	Address // Embedded struct.
}

type User struct {
	ID int `json:"id"` // Tags em structs.
	Name string `json:"name"`
}

type Circle struct {
	Radius float64
}

func (c Circle) Area() float64 {
	return 3.14 * c.Radius * c.Radius
}

func (p *Person) Birthday() {
	p.Age++
}

func main() {
	p := Person{Name: "Gii", Age: 20}
	fmt.Println(p.Name)

	e := Employee{Name: "criskell", Address: Address{City: "SP"}}
	fmt.Println(e.City) // Conseguimos acessar diretamente.

	jsonData, _ := json.Marshal(User{ID: 1, Name: "Jerry"})
	fmt.Println(string(jsonData))

	c := Circle{Radius: 2.5}
	fmt.Println(c.Area()) // 19.625

	p.Birthday()
	fmt.Println(p.Age)

	p2 := Person{"criskell", 20}
	p3 := Person{"criskell", 20}

	// Podemos comparar structs se todos os campos forem comparáveis.
	fmt.Println(p2 == p3)
	fmt.Println(p2 == p2)
	fmt.Println(p == p2)

	person := struct {
		Name string
		Age int
	}{
		Name: "Leonardo",
		Age: 23,
	}

	fmt.Println(person)

	people := []Person{
		{Name: "A", Age: 10},
		{Name: "B", Age: 20},
	}

	fmt.Println(people)

	var structWithZeroValue Person
	fmt.Println(string(must(json.Marshal(structWithZeroValue))))
	fmt.Println(func () string {
		b, _ := json.Marshal(structWithZeroValue)
		return string(b)
	}())
}

func must(b []byte, err error) []byte {
	if err != nil {
		panic(err)
	}

	return b
}

