//Inputs
const int ybIn = 4;
const int rbIn = 12;
const int rstbIn = 13;

//Is Activated?!?
int rLEDState = 0;
int yLEDState = 0;
int rstState = 0;

//Outputs
const int yLEDOut = 2;
const int rLEDOut = 8;
const int buzzOut = 7;

int winner = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ybIn, INPUT);
  pinMode(rbIn, INPUT);
  pinMode(rstbIn, INPUT);
  
  pinMode(yLEDOut, OUTPUT);
  pinMode(rLEDOut, OUTPUT);
  
  pinMode(buzzOut, OUTPUT);
}

void loop() {
  winner = 0;
  rLEDState = digitalRead(rbIn);
  yLEDState = digitalRead(ybIn);
  rstState = digitalRead(rstbIn);
  
  if (rLEDState == HIGH) {
    winner = 1;
    resetButton();
  } 
  
  else if (yLEDState == HIGH) {
    winner = 2;
    resetButton();
  }
}

//Where the magic happens
void resetButton() {  
  if (winner == 1) {
    while(rstState == LOW) {
      rstState = digitalRead(rstbIn);
      digitalWrite(rLEDOut, HIGH);
      digitalWrite(yLEDOut, LOW);
      tone(buzzOut, 440);
    }
    digitalWrite(rLEDOut, LOW);
    noTone(buzzOut);
  }
  
  else if (winner == 2) {
    while(rstState == LOW) {
      rstState = digitalRead(rstbIn);
      digitalWrite(rLEDOut, LOW);
      digitalWrite(yLEDOut, HIGH);
      tone(buzzOut, 660);    
    }
    digitalWrite(yLEDOut, LOW);
    noTone(buzzOut);
  }
} 
    
 
