//Inputs
const int ybIn = 4;
const int rbIn = 12;

//Is Activated?!?
int rLEDState = 0;
int yLEDState = 0;

//Outputs
const int yLEDOut = 2;
const int rLEDOut = 8;
const int buzzOut = 7;

void setup() {
  Serial.begin(9600);
  
  pinMode(ybIn, INPUT);
  pinMode(rbIn, INPUT);
  
  pinMode(yLEDOut, OUTPUT);
  pinMode(rLEDOut, OUTPUT);
  
  pinMode(buzzOut, OUTPUT);
}

void loop() {
  rLEDState = digitalRead(rbIn);
  yLEDState = digitalRead(ybIn);
  
  if (rLEDState == HIGH) {
    digitalWrite(rLEDOut, HIGH);
    digitalWrite(yLEDOut, LOW);
    tone(buzzOut, 440, 1500);
  } else if (yLEDState == HIGH) {
    digitalWrite(rLEDOut, LOW);
    digitalWrite(yLEDOut, HIGH);
    tone(buzzOut, 660, 1500);
  } then {
  delay(5000);
  digitalWrite(yLEDOut, LOW);
  digitalWrite(rLEDOut, LOW);
  }
}
    
 
