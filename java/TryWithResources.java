import java.io.FileInputStream;
import java.io.InputStream;

class TryWithResources {
    public static void main(String[] args) {
        try (InputStream file = new FileInputStream("./TryWithResources.java")) {
            int currentByte = file.read();

            while (currentByte != -1) {
                System.out.print((char) currentByte);

                currentByte = file.read();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}