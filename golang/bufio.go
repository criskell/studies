package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Digite o seu primeiro nome")
	primeiroNome, _ := reader.ReadString('\n')

	fmt.Println("Digite o seu último nome")
	ultimoNome, _ := reader.ReadString('\n')

	fmt.Println("Digite a sua idade: ")
	idade, _ := reader.ReadString('\n')

	fmt.Printf("Nome: %s %s\nIdade: %s", strings.ReplaceAll(primeiroNome, "\r\n", ""), strings.ReplaceAll(ultimoNome, "\r\n", ""), strings.ReplaceAll(idade, "\r\n", ""))
}
