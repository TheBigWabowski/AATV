// Copyright Ephraim Benson 2015

byte rightXPin = 0;
byte rightYPin = 1;
byte killSwitchPin = 3;

byte servoSteering  = 4;

byte servoLeft = 10;
byte servoRight = 11;

byte LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(rightXPin, INPUT);
  pinMode(rightYPin, INPUT);
  pinMode(killSwitchPin, INPUT);

  pinMode(servoLeft, OUTPUT);
  pinMode(servoRight, OUTPUT);
  pinMode(servoSteering, OUTPUT);

  pinMode(LED, OUTPUT);
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
    delay(20);
  }
}