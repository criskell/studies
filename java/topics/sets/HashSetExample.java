
import java.util.HashSet;
import java.util.Set;

public class HashSetExample {

    public static void main(String[] args) {
        Set<String> fruits = new HashSet<>();
        fruits.add("apple");
        fruits.add("banana");
        fruits.add("grape");
        System.out.println(fruits);
        fruits.remove("banana");
        System.out.println(fruits);
        System.out.println(fruits.size());
        fruits.clear();
        System.out.println(fruits.size());
    }
}
