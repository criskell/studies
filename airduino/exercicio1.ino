int ledPin = 13;
int tempoLigado = 500;
int tempoDesligado = 300;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(tempoLigado);

  digitalWrite(ledPin, LOW);
  delay(tempoDesligado);
}
