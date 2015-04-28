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

int valueX = pulseIn(rightXPin, HIGH);
int valueY = pulseIn(rightYPin, HIGH);
int valueKillSwitch = pulseIn(killSwitchPin, HIGH);

void setup() {
  Serial.begin(9600);
  pinMode(rightXPin, INPUT);
  pinMode(rightYPin, INPUT);

  pinMode(killSwitchPin, INPUT);

  pinMode(servoLeft, OUTPUT);
  pinMode(servoRight, OUTPUT);

  pinMode(driverPower, OUTPUT);
  pinMode(driverPolarity, OUTPUT);


  pinMode(LEDPin, OUTPUT);
}

void loop() {
  valueX = pulseIn(rightXPin, HIGH);
  valueY = pulseIn(rightYPin, HIGH);
  valueKillSwitch = pulseIn(killSwitchPin, HIGH);

  bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
  if (shouldRun) {
    function();
    // autonomous switch here
  }
}


void function() {
  yAxis = map(rightYPin, 1000, 1800, 0, 2);
  if (yAxis = 0) {                                    //Test for Reverse
    driveReverse();
    Serial.println("Reverse");
  }
  else if (yAxis = 1) {                             //Test for No Movement
    driveStop();
    Serial.println("No Movement");
  }
  else if (yAxis = 2) {                    //Test for Forward
    driveForward();
    Serial.println("Forward");
  }
  else {
    digitalWrite(LEDPin, HIGH);
  }
  xAxis = map(rightXPin, 1000, 1800, 1000, 2000);
  analogWrite(steeringPin, xAxis);
  delay(10);
}
