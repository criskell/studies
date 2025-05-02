int a = 5;
int b = 2;
float resultado;

void setup() {
  Serial.begin(9600);
  resultado = (float)a / b;
  Serial.println(resultado);
}

void loop() {}
