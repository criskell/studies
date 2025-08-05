
import java.lang.reflect.InvocationTargetException;

public class ReflectionTest {

    private final int x = 10;

    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, InstantiationException, IllegalAccessException, IllegalArgumentException, InvocationTargetException {
        Class<?> clazz = ReflectionTest.class;
        System.out.println(clazz.getName());

        var className = "ReflectionTest";
        var x = (ReflectionTest) Class.forName(className).getDeclaredConstructor().newInstance();

        System.out.println(x.x);
    }
}
