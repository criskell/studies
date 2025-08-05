
import java.util.ArrayList;
import java.util.List;

public class Wildcards {

    public static void main(String[] args) {
        // Wilcard representa um tipo desconhecido.

        // Leitura segura (produtor - o container irá produzir valores)
        // Não pode adicionar, pois o compilador não sabe o tipo exato.
        // Não nos importamos com o tipo do elemento, somente com a estrutura.
        // * Qualquer tipo que seja subclasse de T (ou T).
        List<? extends Number> numbers = List.of(1, 2.5, 3L);

        System.out.println(numbers);

        // Number n = numbers.add(10);
        // Escrita segura (consumidor - o container irá receber valores)
        // * Qualquer tipo que seja superclasse de T (ou T).
        List<? super Integer> numbers2 = new ArrayList<>();
        numbers2.add(10);

        Object obj = numbers2.get(0);

        System.out.println(numbers2);
        System.out.println(obj);

        // Effective Java - Regra do Pecs
        // Producer -> extends
        // Consumer -> super
    }
}
