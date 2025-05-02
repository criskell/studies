int pinoBotao = 2;
int totalCliques = 0;
int leituraAtual = 0;
int leituraAnterior = 0;

void setup() {
  pinMode(pinoBotao, INPUT);
  Serial.begin(9600);
}

void loop() {
  leituraAtual = digitalRead(pinoBotao);

  if (leituraAtual == HIGH && leituraAnterior == LOW) {
    totalCliques++;
    Serial.println(totalCliques);
    delay(200);
  }

  leituraAnterior = leituraAtual;
}
