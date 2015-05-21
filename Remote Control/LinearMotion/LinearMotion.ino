// Linear_Motion.ino by Archer O'Neal-Odom and Ephraim Benson on May 20th, 2015
// A medium sized car designed to be ridden by children that has been repurposed for 
// Remote Control and partial autonomous function.


// SERVO PINS 
const byte rightXPin = 0;
const byte rightYPin = 1;
const byte killSwitchPin = 3;
const byte IRPin = 14;
const byte servoLeft = 10;
const byte servoRight = 11;
const byte servoSteer = 6;
const byte LEDPin = 13;

// CONSTANTS 
byte xAxis = 0;
byte yAxis = 0;

int valueX = 0;
int valueY = 0;
int valueKillSwitch = 0;

int rightSteerPulseWidth = 2400;
int leftSteerPulseWidth = 750;

String currentSteerPos = "";

void setup() {
  Serial.begin(9600);
  pinMode(rightXPin, INPUT);
  pinMode(rightYPin, INPUT);

  pinMode(killSwitchPin, INPUT);

  pinMode(servoLeft, OUTPUT);
  pinMode(servoRight, OUTPUT);

  pinMode(servoSteer, OUTPUT);


  pinMode(IRPin, INPUT);

  pinMode(LEDPin, OUTPUT);
}

void loop() {
  turnRight();     // <----- Code to Run goes here (currently test code)
}


//void function() {
//  int valueX = pulseIn(rightXPin, HIGH);
//  int valueY = pulseIn(rightYPin, HIGH);
//  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);
//
//    bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
//      if (shouldRun) {                                   //Test for Kill Switch
//      debug(LEDPin);
//      //Serial.println("ON");
//  if (valueY > 1460) {                                    //Test for Reverse
//    go();
//    Serial.println("FORWARD");                                                                                  //Not used for now
//  }
//  
//      else if (valueY < 1390) {                    //Test for Forward
//        goBack();
//        Serial.println("REVERSE");
//      }
//  else {                            //Test for No Movement
//    halt();
//    Serial.println("STILL");
//  }
//  xAxis = map(valueX, 1000, 1800, 1000, 2000);
//  analogWrite(servoSteer, xAxis);                  //Steering
//  delay(10);
//}
//}

void debug(int pin) {
  digitalWrite(pin, HIGH);
  delay(1000);                      //Debug a Pin
  digitalWrite(pin, LOW);
  delay(1000);
}

void debugRemote() {
  int valueX = pulseIn(rightXPin, HIGH);
  int valueY = pulseIn(rightYPin, HIGH);
  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);          //Debug the Remote

  Serial.print("Value X = " + (String)valueX + "; Value Y = " + (String)valueY + "; Kill Switch = " + (String)valueKillSwitch);
  Serial.println("");
  delay(100);
}

void turnLeft() {
  ServoMove(servoSteer, leftSteerPulseWidth);
  delay(20);
  currentSteerPos = "left";
}

void turnRight(){
  ServoMove(servoSteer, rightSteerPulseWidth);
  delay(20);
  currentSteerPos = "right";
}

void alignStraight() {
  currentSteerPos = "straight";
}
