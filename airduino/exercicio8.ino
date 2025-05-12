int valorNivel;
void setup() {
  Serial.begin(9600);
}

void loop() {
  valorNivel = analogRead(A0);
  
  if (valorNivel < 341) {
    Serial.println("Nivel: Baixo");
  } else if (valorNivel < 682) {
    Serial.println("Nivel: Medio");
  } else {
    Serial.println("Nivel: Alto");
  }

  delay(1000);
}
