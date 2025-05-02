int pinoSensor = A0;
float temperaturaC;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinoSensor);
  temperaturaC = leitura * 5.0 * 100.0 / 1023.0;
  Serial.println("Temperatura: ");
  Serial.println(temperaturaC);
  delay(1000);
}
