int leituraSensor;
char status = 'N';

void setup() {
  Serial.begin(9600);
}

void loop() {
  leituraSensor = analogRead(A0);

  if (leituraSensor < 341) {
    status = 'N';
  } else if (leituraSensor < 682) {
    status = 'A';
  } else {
    status = 'P';
  }

  Serial.print("Status: ");
  Serial.println(status);
  delay(1000);
}
