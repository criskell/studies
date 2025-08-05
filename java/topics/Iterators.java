
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

public class Iterators {

    public static void main(String[] args) {
        List<String> names = List.of("eren", "mikasa", "armin");
        Iterator<String> it = names.iterator();

        while (it.hasNext()) {
            String name = it.next();
            System.out.println("Name: " + name);
            // it.remove() - remove o elemento atual da coleção.
        }

        List<String> list = new ArrayList<>(List.of("Alfa", "Beta", "Gama"));

        ListIterator<String> listIt = list.listIterator();

        while (listIt.hasNext()) {
            System.out.println(listIt.next());
        }

        while (listIt.hasPrevious()) {
            System.err.println(listIt.previous());
        }

        listIt.set("Alfa - updated");
        System.out.println(list);

        listIt.next();
        listIt.next();
        listIt.remove();

        System.out.println("After remove: " + list);
    }
}
