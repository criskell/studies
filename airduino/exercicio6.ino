int leitura1, leitura2, leitura3;
float media;

void setup() {
  Serial.begin(9600);
}

void loop() {
  leitura1 = analogRead(A0);
  leitura2 = analogRead(A0);
  leitura3 = analogRead(A0);
  
  media = (leitura1 + leitura2 + leitura3) / 3.0;
  
  Serial.println(media);
  delay(1000);
}
