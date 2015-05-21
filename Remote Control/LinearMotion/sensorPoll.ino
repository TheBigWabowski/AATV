// Linear_Motion.ino by Archer O'Neal-Odom and Ephraim Benson on May 20th, 2015
// A medium sized car designed to be ridden by children that has been repurposed for 
// Remote Control and partial autonomous function.

void getDistance(){
 int IRValue = analogRead(IRPin);   //         <--------- 150 ~=~ 100cm
 if(IRValue <= 50){
  go(); 
 }
// else{halt();}
}
