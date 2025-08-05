
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;

public class HashTreeMap {

    public static void main(String[] args) {
        // HashMap:
        // - Hash table.
        // - O(1) para operações de busca, inserção e remoção (em média).
        // - Não garante ordem das chaves.
        // - Permite chaves nulas.
        // - Não é sincronizado.
        // - Permite chaves duplicadas (substitui o valor).
        Map<String, Integer> map = new HashMap<>();
        map.put("notebook", 1);
        map.put("mouse", 2);
        map.put("keyboard", 3);
        map.put("monitor", 4);

        // TreeMap:
        //  - Red-black tree.
        //  - O(log n) para operações de busca, inserção e remoção.
        //  - Ordenação natural ou por comparador.
        //  - Não permite chaves nulas.
        Map<String, Integer> treeMap = new HashMap<>();
        treeMap.put("notebook", 1);
        treeMap.put("mouse", 2);
        treeMap.put("keyboard", 3);
        treeMap.put("monitor", 4);

        // LinkedHashMap:
        // - Utiliza HashMap e uma lista duplamente ligada para manter a ordem.
        // - O(1) para operações de busca, inserção e remoção (em média).
        // - Mantém a ordem de inserção ou ordem de acesso.
        // - Permite chaves nulas.
        Map<String, Integer> linkedHashMap = new LinkedHashMap<>();
        linkedHashMap.put("notebook", 1);
        linkedHashMap.put("mouse", 2);
        linkedHashMap.put("keyboard", 3);
        linkedHashMap.put("monitor", 4);

        System.err.println("HashMap:");

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }

        System.out.println("TreeMap:"); // vai exibir em ordem alfabética (a ordem natural das chaves)

        for (Map.Entry<String, Integer> entry : treeMap.entrySet()) {
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }

        System.out.println("LinkedHashMap:");

        for (Map.Entry<String, Integer> entry : linkedHashMap.entrySet()) {
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }
    }
}
