
public class FunctionalAdapterMusicPlayerApp {

    public static void main(String[] args) {
        var mp3Player = new Mp3Player();
        AudioPlayer audioPlayer = fileName -> mp3Player.playMp3(fileName);
        audioPlayer.play("music.mp3");

        var wavPlayer = new WavPlayer();
        audioPlayer = fileName -> wavPlayer.playWav(fileName);
        audioPlayer.play("music.wav");

        var flacPlayer = new FlacPlayer();
        audioPlayer = fileName -> flacPlayer.playFlac(fileName);
        audioPlayer.play("music.flac");
    }
}

// Target Interface
@FunctionalInterface
interface AudioPlayer {

    void play(String fileName);
}

// Adaptee
class FlacPlayer {

    public void playFlac(String fileName) {
        System.out.println("Playing flac file: " + fileName);
    }
}

class WavPlayer {

    public void playWav(String fileName) {
        System.out.println("Playing wav file: " + fileName);
    }
}

class Mp3Player {

    public void playMp3(String fileName) {
        System.out.println("Playing mp3 file: " + fileName);
    }
}
