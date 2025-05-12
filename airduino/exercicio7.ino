const int pinoLED = 13;
const int pinoBotao = 2;

void setup() {
  pinMode(pinoLED, OUTPUT);
  pinMode(pinoBotao, INPUT);
}

void loop() {
  if (digitalRead(pinoBotao) == HIGH) {
    digitalWrite(pinoLED, HIGH);
  } else {
    digitalWrite(pinoLED, LOW);
  }
}
