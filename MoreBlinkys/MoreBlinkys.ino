
const int ledPin = 8;
const int highPot = A0;
const int lowPot = A1;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(highPot, INPUT);
  pinMode(lowPot, INPUT);
}

void loop() {
  int h = analogRead(highPot) / 10;
  int l = analogRead(lowPot) / 10;
  
//  Serial.println(h);
//  Serial.println(-1 * l);


  
  digitalWrite(ledPin, HIGH);
  delay(1 + h);
  digitalWrite(ledPin, LOW);
  delay(1 + h);
}
