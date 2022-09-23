const int ledpin = 8;
const int btnpin = 2;

volatile int state = LOW;


void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(btnpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(btnpin) == LOW) {
    delay(10);
    if(digitalRead(btnpin) == LOW) {
      Serial.println("past if");
      while(digitalRead(btnpin) == LOW); //I suppose this just blocks until? janky code or common convention?
      state = !state;
      digitalWrite(ledpin, state);
      Serial.println(state);
    }
  }
}
