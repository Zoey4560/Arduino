const int rows[8] = {2, 3, 4, 5, 6, 7, 8, 9};
const int columns[8] = {A1, A2, A3, A4, A5, A6, A7, A8};

int sample[8][8] = {
    {0, 1, 1, 0, 0, 1, 1, 0},
    {1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};



void render(int input[8][8], int delayTime = 2) {
  for(int i = 0; i < 8; i++) {
      digitalWrite(rows[i], HIGH);
      for(int j = 0; j < 8; j++) {
        if(input[i][j] == 1) {
            digitalWrite(columns[j], LOW);
        }
      }
      delay(delayTime);
      zeroColumns();
      digitalWrite(rows[i], LOW);
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(rows[i], OUTPUT);
    pinMode(columns[i], OUTPUT);
  }
  zero();
}

void loop() {
  render(sample);
}


void zero(){
  zeroRows();
  zeroColumns();  
}

void zeroRows() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(rows[i], LOW);
  }
}

void zeroColumns() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(columns[i], HIGH);
  }
}
