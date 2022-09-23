
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

const int PLOT_DELAY = 100;
unsigned long nextPlot = 0;

volatile int fps = 60;


void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(meter, INPUT);
  
  pinMode(decButton, INPUT_PULLUP);  // pullup button switches sit HIGH when open and drop LOW when pressed.
  pinMode(incButton, INPUT_PULLUP);
  lastDec = digitalRead(decButton);
  lastInc = digitalRead(incButton);

  attachInterrupt(digitalPinToInterrupt(decButton), decrement, CHANGE);
  attachInterrupt(digitalPinToInterrupt(incButton), increment, CHANGE);
  
  Serial.println("setup complete");
}

void loop() {
  // ---- Calculations ----
  int period = (1000 / fps);

  float ratio = analogRead(meter) / 1023.0; // [0 - 1023]

  float uptime = period * ratio;
  float downtime = period * (1 - ratio);


  // ---- Delay ----
  digitalWrite(led, HIGH);
  floatDelay(uptime);

  digitalWrite(led, LOW);
  floatDelay(downtime);

  // TODO/OPTIMIZE
  // - Do math once, then drive the LED for a handfull of cycles; more speed/accuracy at the low lvls.
  //   - already tried w/ 1 sec clusters; felt laggy AF
  // - How much time is spent doing math (while LOW)?


  // ---- Plotter ----
  // // ** WARNING **
  // //  * Only turn this on for debugging; not when trying to drive the LED.
  // //    Writing to Serial is _sloooooooowwwww_ (comparatively)
  // //    and creates extra time that the led is LOW, a visible blink
  // plot(period, ratio, uptime, downtime);
}



void decrement() {
  buttonPress(lastDec, -5);
  lastDec = digitalRead(decButton);
}

void increment() {
  buttonPress(lastInc, 5);
  lastInc = digitalRead(incButton);
}

void buttonPress(int last, int delta) {
  unsigned long now = millis();
  if (last == HIGH && now > debounceUntil) {
    fps += delta;
    if (fps < 1) {
      fps = 1;
    }
  }
  debounceUntil = now + DEBOUNCE_DELAY;
}

void floatDelay(float ms) {
  delay(int(ms));
  delayMicroseconds(round(ms * 1000) % 1000);
}

void plot(int p, float r, float u, float d) {
  unsigned int now = millis();
  if (now > nextPlot) {
    Serial.print("fps:");
    Serial.print(fps);
    Serial.print(",period:");
    Serial.print(p);
    Serial.print(",ratio:");
    Serial.print(r);
    Serial.print(",uptime:");
    Serial.print(u);
    Serial.print(",downtime:");
    Serial.print(d);
    Serial.print(",error:");
    Serial.print(p - (u + d));
    Serial.println("");

    nextPlot = now + PLOT_DELAY;
  }
}
