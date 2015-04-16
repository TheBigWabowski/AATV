
// Copyright Ephraim Benson 2015

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
<<<<<<< HEAD
  
  pinMode(driverPower, OUTPUT);
  pinMode(driverPolarity = OUTPUT);
=======
  pinMode(servoSteering, OUTPUT);
  pinMode(driverPin, OUTPUT);
>>>>>>> origin/master


  pinMode(LEDPin, OUTPUT);
}

void loop() {
  
}


void main(){ 
  int valueX = pulseIn(rightXPin, HIGH);
  int valueY = pulseIn(rightYPin, HIGH);
  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);
  int valueX_remapped = map(valueX, 1000, 1800, 0, 2);

  bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
<<<<<<< HEAD
  if (shouldRun) {                                   //Test for Kill Switch
    yAxis = map(rightYPin, 1000, 1800, 0, 2);
    if (yAxis = 0){                                     //Test for Reverse
      driverReverse();
    }
    else if (yAxis = 1){                              //Test for No Movement
     driverStop(); 
    }
    else if (yAxis = 2){                     //Test for Forward
     driverForward();
    }
    else {digitalWrite(LEDPin, HIGH)};
=======
  if (shouldRun) {

  	// Y Movement
    ServoMove(servoLeft, 2000- valueY + 1000);
    ServoMove(servoRight, valueY);

    // X Movement
    if (valueX_remapped == 0) {
    	ServoMove(servoSteering, 1000);
    	Serial.println("left");
    } else if (valueX_remapped == 2) {
    	Serial.println("right");
    	ServoMove(servoSteering, 2000);
    } else {
    	Serial.println("forward");
    	ServoMove(servoSteering, 1500);
    }
    
    practiceDriverForward();

    delay(20);
>>>>>>> origin/master
  }
    xAxis = map(rightXPin, 1000, 1800, 1000, 2000);
     analogWrite(steeringPin, xAxis);
  delay(10);
}
