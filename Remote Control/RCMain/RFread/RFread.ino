const byte rightXPin = 0;
const byte rightYPin = 1;
const byte killSwitchPin = 3;

const byte driverPower = 8;
const byte driverPolarity = 9;
const byte steeringPin = 7;

byte xAxis = 0;
byte yAxis = 0;

const byte servoLeft = 10;
const byte servoRight = 11;

const byte LEDPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(rightXPin, INPUT);
  pinMode(rightYPin, INPUT);

  pinMode(killSwitchPin, INPUT);

  pinMode(servoLeft, OUTPUT);
  pinMode(servoRight, OUTPUT);

  pinMode(driverPower, OUTPUT);
  pinMode(driverPolarity, OUTPUT);
  pinMode(steeringPin, OUTPUT);


  pinMode(LEDPin, OUTPUT);
}

void loop() {
  function();
  //debugRemote();
//  digitalWrite(driverPolarity, HIGH);
//  delay(500);
//  digitalWrite(driverPolarity, LOW);
//  delay(500);
//  digitalWrite(driverPower, HIGH);
//  delay(500);
//  digitalWrite(driverPower, LOW);
//  delay(500);
}


void function() {
  int valueX = pulseIn(rightXPin, HIGH);
  int valueY = pulseIn(rightYPin, HIGH);
  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);

  bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
  if (shouldRun) {                                     //Test for Kill Switch
    //Serial.println("ON");
    if (valueY > 1460) {                                    //Test for Reverse
      driveForward();
      Serial.println("FORWARD");
    }
    
    else if (valueY < 1390) {                    //Test for Forward
      driveReverse();
      Serial.println("REVERSE");
    }
    else{                             //Test for No Movement
      driveStop();
      Serial.println("STILL");
    }
    xAxis = map(valueX, 1000, 1800, 1000, 2000);
    analogWrite(steeringPin, xAxis);
    delay(10);
  }
  else{
    Serial.println("OFF");
  }
  delay(100);
}

void debug(int pin){
  digitalWrite(pin, HIGH); 
}

void debugRemote(){
  int valueX = pulseIn(rightXPin, HIGH);
  int valueY = pulseIn(rightYPin, HIGH);
  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);

  Serial.print("Value X = " + (String)valueX + "; Value Y = " + (String)valueY + "; Kill Switch = " + (String)valueKillSwitch);   
  Serial.println("");
  delay(100);
}

