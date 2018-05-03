//Hashem Alnader January 2018

int motorPin = 3;
int button = 7;
bool condition;
unsigned long tStart = 0;
unsigned long tEnd = 0;
int potValInit = 300;
//bool drift = false;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
  Serial.begin(115200);
  while (! Serial);
}
void loop()
{
  //tEnd = millis();
  condition = digitalRead(button);
  int potVal = analogRead(A0);
  int potValEnd = potVal;
  int rotSpeed = map(potVal, 400, 1023, 120, 255);
  /*
  Attempt to deal with sensor drift through software
  
  if ((tEnd - tStart) > 4000){
    tStart = tEnd;
    if (potValEnd - potValInit < 500 && potValEnd - potValInit > 0){
      potValInit = potValEnd;
      drift = true;
    }
  }
  else 
    drift = false;
  
  if (potVal <= 405){
    rotSpeed = 0;
  }
  if (drift){
    rotSpeed = 0;
  }
  */
  if (condition == LOW){
  analogWrite(motorPin, rotSpeed);
  }
  else{
  analogWrite(motorPin, 0);
  }
  Serial.print("Potentiometer Value ");
  Serial.print(potVal);
  Serial.print(" Pump Speed ");
  Serial.println(rotSpeed);
  Serial.print(condition);
}
