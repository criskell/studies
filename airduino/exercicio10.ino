int pinoRele = 8;
int pinoBotao = 2;
int tempoAtuacao = 5000;
int estadoAtual = 0;
int estadoAnterior = 0;

void setup() {
  pinMode(pinoRele, OUTPUT);
  pinMode(pinoBotao, INPUT);
}

void loop() {
  estadoAtual = digitalRead(pinoBotao);

  if (estadoAtual == HIGH && estadoAnterior == LOW) {
    digitalWrite(pinoRele, HIGH);
    delay(tempoAtuacao);
    digitalWrite(pinoRele, LOW);
  }

  estadoAnterior = estadoAtual;
}
