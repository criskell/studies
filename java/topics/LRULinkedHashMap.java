
import java.util.LinkedHashMap;
import java.util.Map;

// Least Recently Used (LRU) cache - menos recentemente usado
class LRUCache<K, V> extends LinkedHashMap<K, V> {

    private final int maxCapacity;

    public LRUCache(int maxCapacity) {
        super(maxCapacity, 0.75f, true); // true para ordem de acesso
        // 0.75f é o fator de carga padrão, que equilibra o uso de memória e a performance
        this.maxCapacity = maxCapacity;
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<K, V> eldest) {
        return size() > maxCapacity;
    }
}

public class LRULinkedHashMap {

    public static void main(String[] args) {
        LRUCache<String, String> lruCache = new LRUCache<>(3);

        lruCache.put("p1", "eren");
        lruCache.put("p2", "mikasa");
        lruCache.put("p3", "armin"); // é o mais recentemente usado

        System.out.println(lruCache);

        lruCache.get("p1"); // p1 é o mais recentemente usado
        lruCache.put("p4", "levi"); // excedemos a capacidade. remove o menos usado (p2)

        System.out.println(lruCache);

        lruCache.put("p5", "sasha"); // remove o menos usado (p3)

        System.out.println(lruCache);
    }
}
