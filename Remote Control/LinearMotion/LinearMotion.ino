// Linear_Motion.ino by Archer O'Neal-Odom and Ephraim Benson on May 20th, 2015
// A medium sized car designed to be ridden by children that has been repurposed for
// Remote Control and partial autonomous function.


// SERVO PINS
const byte rightXPin = 0;
const byte rightYPin = 1;
const byte killSwitchPin = 3;
const byte IRPin = 14;
const byte servoSteer = 6;
const byte LEDPin = 13;
const byte relayPower = 8;
const byte relayPolarity = 9;

// CONSTANTS
byte xAxis = 0;
byte yAxis = 0;

int valueX = 0;
int valueY = 0;
int valueKillSwitch = 0;

int rightSteerPulseWidth = 2500;
int leftSteerPulseWidth = 700;
int middleSteerPulseWidth = 1450;

String currentSteerPos = "";

void setup() {
  Serial.begin(9600);
  pinMode(rightXPin, INPUT);
  pinMode(rightYPin, INPUT);
  pinMode(killSwitchPin, INPUT);

  pinMode(servoSteer, OUTPUT);

  pinMode(relayPower, OUTPUT);
  pinMode(relayPolarity, OUTPUT);
  pinMode(IRPin, INPUT);

  pinMode(LEDPin, OUTPUT);
}

void givePower() {
  digitalWrite(relayPower, HIGH);
  //  digitalWrite(relayPolarity, HIGH);
  //  delay(3000);
  //  digitalWrite(relayPolarity, LOW);
  delay(1000);
  digitalWrite(relayPower, LOW);
  delay(1000);

  //  delay(4000);
  //  digitalWrite(relayPolarity, LOW);
  //  delay(4000);
  //  digitalWrite(relayPower, LOW);
}

void loop() {
  //debugRemote();
  mainFunction();
  //  givePower();

  //  turnRight();

  //getDistance();



}

void mainFunction() {
  valueX = pulseIn(rightXPin, HIGH);
  valueY = pulseIn(rightYPin, HIGH);
  valueKillSwitch = pulseIn(killSwitchPin, HIGH);

  bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
  if (shouldRun) {
    Serial.println("Should run");

    xAxis = map(valueX, 1000, 1800, 0, 2);
    //Serial.println(xAxis);
    if (xAxis == 2) { // left
      turnRight();
    } else if (xAxis == 1) { // straight
      alignStraight();
    } else if (xAxis == 0) {
      turnLeft();
    } else {
      Serial.println("ERROR: INCOMPATIBLE X VALUE");
    }

    yAxis = map(valueY, 1000, 1800, 0, 1);
    Serial.println(yAxis);
    if (yAxis == 1) { // stop
      digitalWrite(relayPower, HIGH);
    } else if (yAxis == 0) { // forward
      digitalWrite(relayPower, LOW);
    } else {
      Serial.println("ERROR: INCOMPATIBLE Y VALUE");
    }

  } else {
    digitalWrite(relayPower, LOW); //STOP THE CAR
  }
}


void function() {
  int valueX = pulseIn(rightXPin, HIGH);
  int valueY = pulseIn(rightYPin, HIGH);
  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);

  bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
  if (shouldRun) {                                   //Test for Kill Switch
    Serial.println("ON");
    //  if (valueY > 1460) {                                    //Test for Reverse
    //    go();
    //    Serial.println("FORWARD");
    //  }
    //
    //    else if (valueY < 1390) {                    //Test for Forward
    //      goBack();
    //      Serial.println("REVERSE");
  }
  else {                            //Test for No Movement
    //    halt();
    // Serial.println("STILL");
  }
  xAxis = map(valueX, 1000, 1800, 1000, 2000);
  analogWrite(servoSteer, xAxis);
  delay(10);
}
}

void loop() {
  turnRight();     // <----- Code to Run goes here (currently test code)
  alignStraight();
  turnLeft();
  alignStraight();
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
  for (int i = 0; i < 5; i++) {
    ServoMove(servoSteer, leftSteerPulseWidth);
    delay(10);
  }
  currentSteerPos = "left";
}

void turnRight() {
  for (int i = 0; i < 5; i++) {
    ServoMove(servoSteer, rightSteerPulseWidth);
    delay(10);
  }
  currentSteerPos = "right";
}

void alignStraight() {
  for (int i = 0; i < 5; i++) {
    ServoMove(servoSteer, middleSteerPulseWidth);
    delay(10);
  }
  digitalWrite(LEDPin, LOW);
  delay(1000);
  currentSteerPos = "left";
}
