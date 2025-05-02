int pinoBotao = 2;
int pinoLed = 13;
bool ledLigado = false;

int leituraAtual = 0;
int leituraAnterior = 0;

void setup() {
  pinMode(pinoBotao, INPUT);
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  leituraAtual = digitalRead(pinoBotao);

  if (leituraAtual == HIGH && leituraAnterior == LOW) {
    ledLigado = !ledLigado;
    digitalWrite(pinoLed, ledLigado ? HIGH : LOW);
    delay(200);
  }

  leituraAnterior = leituraAtual;
}
