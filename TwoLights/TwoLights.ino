
// Runs one light on a variable duty cycle
// and one light on an interverlometer
// (we only need code for the first light)

const int led = 8;
const int meter = A0;

const int decButton = 2;
const int incButton = 3;

volatile int lastDec;
volatile int lastInc;

const int DEBOUNCE_DELAY = 50;
volatile unsigned long debounceUntil = 0;

volatile int fps = 10;


void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(meter, INPUT);
  
  pinMode(decButton, INPUT_PULLUP);  // pullups sit HIGH and drop LOW when pressed.
  pinMode(incButton, INPUT_PULLUP);
  lastDec = digitalRead(decButton);
  lastInc = digitalRead(incButton);

  attachInterrupt(digitalPinToInterrupt(decButton), decrement, CHANGE);
  attachInterrupt(digitalPinToInterrupt(incButton), increment, CHANGE);
  
  Serial.println("setup complete");
}

void loop() {
  // ---- Calculations ----
  int wait = (1000 / fps) - 2; // -2 for min of 1 offset

  float ratio = (analogRead(meter)) / 1023.0; // [0 - 1023]

  float uptime = (1 + (wait * ratio * 1000.0));
  float downtime = (1 + (wait * (1 - ratio) * 1000.0));


  // ---- Delay ----
  digitalWrite(led, HIGH);
  delayMicroseconds(uptime);
  digitalWrite(led, LOW);
  delayMicroseconds(downtime);


  // ---- Plotter ----
  // ** WARNING **
  //  * Only turn this on for debugging; not when trying to drive the LED. Writing to Serial is _sloooooooowwwww_
  Serial.print("fps:");
  Serial.print(fps);
  Serial.print(",wait:");
  Serial.print(wait);
  Serial.print(",ratio:");
  Serial.print(ratio);
  Serial.print(",uptime:");
  Serial.print(uptime);
  Serial.print(",downtime:");
  Serial.print(downtime);
  Serial.print(",error:");
  Serial.print(wait - (uptime + downtime));
  Serial.println("");
}

// void Delay(float micro) {

// }

void decrement() {
  int current = digitalRead(decButton);
  buttonPress(current, lastDec, -1);
  lastDec = current;
}

void increment() {
  int current = digitalRead(incButton);
  buttonPress(current, lastInc, 1);
  lastInc = current;
}

void buttonPress(int pin, int last, int delta) 
  if (last == LOW) {
    debounce();
    return;
  }

  if (millis() < debounceUntil) {
    debounce();
    return;
  }

  fps += delta;
  if (fps < 1) {
    fps = 1;
  }
  debounce();
  Serial.print("fps:");
  Serial.println(fps);
}

void debounce() {
  debounceUntil = millis() + DEBOUNCE_DELAY;
}
