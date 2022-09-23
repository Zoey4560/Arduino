const int ledPin = 8;
const int pot = A0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  float x = analogRead(pot) * (255.0 / 1024.0);
  Serial.println(x);
  analogWrite(ledPin, x);
  delay(100);
}
