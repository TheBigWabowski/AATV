
// Copyright Ephraim Benson 2015

const byte rightXPin = 0;
const byte rightYPin = 1;
const byte killSwitchPin = 3;

const byte driverPin = 9;

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
  pinMode(servoSteering, OUTPUT);
  pinMode(driverPin, OUTPUT);


  pinMode(LEDPin, OUTPUT);
}

void loop() {
  int valueX = pulseIn(rightXPin, HIGH);
  int valueY = pulseIn(rightYPin, HIGH);
  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);
  int valueX_remapped = map(valueX, 1000, 1800, 0, 2);

  bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
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
  }
}
