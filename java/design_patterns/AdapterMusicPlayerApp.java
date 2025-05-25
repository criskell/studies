
public class AdapterMusicPlayerApp {

    public static void main(String[] args) {
        AudioPlayer mp3Player = new Mp3Player();
        mp3Player.play("music.mp3");

        AudioPlayer wavPlayer = new WavAdapter(new WavPlayer());
        wavPlayer.play("music.wav");

        AudioPlayer flacPlayer = new FlacAdapter(new FlacPlayer());
        flacPlayer.play("music.flac");
    }
}

// Target Interface
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

// Adapters
class WavAdapter implements AudioPlayer {

    private final WavPlayer wavPlayer;

    public WavAdapter(WavPlayer wavPlayer) {
        this.wavPlayer = wavPlayer;
    }

    @Override
    public void play(String fileName) {
        wavPlayer.playWav(fileName);
    }
}

class FlacAdapter implements AudioPlayer {

    private final FlacPlayer flacPlayer;

    public FlacAdapter(FlacPlayer flacPlayer) {
        this.flacPlayer = flacPlayer;
    }

    @Override
    public void play(String fileName) {
        flacPlayer.playFlac(fileName);
    }
}

class Mp3Player implements AudioPlayer {

    @Override
    public void play(String fileName) {
        System.out.println("Playing mp3 file: " + fileName);
    }
}
