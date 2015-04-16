const int leftForwardFast = 1000;
const int leftReverseFast = 2000;
const int rightForwardFast = 2000;
const int rightReverseFast = 1000;

void driveForward(){
  
}

void driveReverse(){
  
}

void driveStop(){
  
}

//Movement:
void forwardFast(int x){
  for(int i=0;i<x;i++){
    forwardStepFast();
  } 
}

void reverseFast(int x){
  for(int i=0;i<x;i++){
    reverseStepFast();
  } 
}

void leftFast(int x){
  for(int i=0;i<x;i++){
    leftStepFast();
  } 
}

void rightFast(int x){
  for(int i=0;i<x;i++){
    rightStepFast();
  } 
}


//Steps:

void forwardStepFast(){
  ServoMove(servoLeft,leftForwardFast);
  ServoMove(servoRight,rightForwardFast);
  delay(20);
}

void reverseStepFast(){
  ServoMove(servoLeft,leftReverseFast);
  ServoMove(servoRight,rightReverseFast);
  delay(20);
}

void rightStepFast(){
  ServoMove(servoLeft,leftForwardFast);
  ServoMove(servoRight,rightReverseFast);
  delay(20);
}

void leftStepFast(){
  ServoMove(servoLeft,leftReverseFast);
  ServoMove(servoRight,rightForwardFast);
  delay(20);
}

// **
void rotateServoRight(){
  ServoMove(servoRight, rightReverseFast);
  delay(20);
}
void rotateServoLeft(){
  ServoMove(servoLeft, leftReverseFast);
  delay(20);
}
// **

//Servo Basics:
void ServoMove(int servo,int PW){
  digitalWrite(servo,HIGH);
  delayMicroseconds(PW);
  digitalWrite(servo,LOW);
}



  
