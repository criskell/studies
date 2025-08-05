
import java.util.Arrays;
import java.util.List;

public class LearnStreams {

    public static void main(String[] args) {
        List<String> words = List.of("java", "stream");

        // flatMap serve para achatar as streams em uma só, quando cada elemento é mapeado para outra stream.
        // (semelhante a monad [] do haskell?)
        List<String> separatedWords = words.stream().flatMap(word -> Arrays.stream(word.split(" "))).toList();

        System.out.println(separatedWords);
    }
}
