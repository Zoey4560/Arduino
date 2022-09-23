
const int trig = 12;
const int ping = 13;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(ping, INPUT);
  digitalWrite(trig, LOW);
  // not sure if starting low is needed; or if I need to delay too?
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  int echo =  pulseIn(ping, HIGH);
  Serial.println(echo / 58);
  delay(100);
}
