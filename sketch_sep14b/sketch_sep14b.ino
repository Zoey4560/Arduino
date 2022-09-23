int sample[8][8] = {
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1}
};


void foo(int a = 10) {
  Serial.println(a);  
}

void setup() {
  Serial.begin(9600);
  // more setup here.. not important.
}

void loop() {
  foo();
  int a = 1;
  foo(a);
  foo(50);
}


void render(int input[8][8]) {
  Serial.println("foo");
}
