byte rightXPin = 0;
byte rightYPin = 1;
byte killSwitchPin = 3;

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


  pinMode(LED, OUTPUT);
}

void loop() {
  int valueX = pulseIn(rightXPin, HIGH);
  int valueY = pulseIn(rightYPin, HIGH);
  int valueKillSwitch = pulseIn(killSwitchPin, HIGH);

  bool shouldRun = map(valueKillSwitch, 1000, 1800, 0, 1);
  if (shouldRun) {
    // forwardFast(1);
    // do all the stuff


    ServoMove(servoLeft, 2000- valueY + 1000);
    ServoMove(servoRight, valueY);
    delay(20);

  }
}