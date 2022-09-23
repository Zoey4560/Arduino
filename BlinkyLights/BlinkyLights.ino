
const int ledPin = 8;
const int dutyPin = A0;
const int periodPin = A1;

int hz = 10;
int maxPeriod = 1000/hz;

int ledState = LOW;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(dutyPin, INPUT);
  pinMode(periodPin, INPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  float duty =  (analogRead(dutyPin) + 1) / 1024.0;
  float period =  (analogRead(periodPin) +1 )/ 1024.0;

  period = period * maxPeriod;


  ledState = 1 - ledState;
  float wait;
  if(ledState == HIGH) {
    wait = period * duty;
  } else {
    wait = period * (1-duty);
  }

  int miliWait = int(wait);
  int microWait = fmod((wait * 1000), 1000);
  

//  if (ledState == 1) {
//    Serial.println(String(ledState) + " " + String(wait) + "  " + String(miliWait) + " " + String(microWait));
//  }
  digitalWrite(ledPin, ledState);
  delay(miliWait);
  delayMicroseconds(microWait);
  
//  for (int i = 0; i < wait; i++) {
////        Serial.println(ledState);
//      delay(1);
//  }
////  } else {
////    Serial.println(-1);  
////  }

  
//  Serial.print(ledState);
//  Serial.print(" ");
//  Serial.print(duty);
//  Serial.print(" ");
//  Serial.print(period);
//  Serial.print(" ");
//  Serial.print(wait);
//  Serial.print(" ");
//  Serial.print((period * duty));
//  Serial.print(" ");
//  Serial.println((period * (1-duty) ));

}
