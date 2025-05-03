#include <iostream>

// decltype retorna o tipo da expressão sem avaliá-la.
// Trailing return type permite a declaração do return type depois dos parâmetros formais.
// É útil quando precisa dos parâmetros em escopo durante a declaração de retorno.
template <typename T, typename U>
auto Add(const T& lhs, const U& rhs) -> decltype(lhs + rhs) {
	return lhs + rhs;
}

int main() {
	std::cout << Add(10, 20);
}
