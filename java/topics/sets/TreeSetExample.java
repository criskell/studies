
import java.util.Set;
import java.util.TreeSet;

public class TreeSetExample {

    public static void main(String[] args) {
        Set<String> names = new TreeSet<>();

        names.add("criskell");
        names.add("ana");
        names.add("ana");

        for (String name : names) {
            System.out.println(name);
        }
    }
}
