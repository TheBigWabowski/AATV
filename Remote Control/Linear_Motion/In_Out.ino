void getDistance(){
 int IRValue = analogRead(IRPin);   //         <--------- 150 ~=~ 100cm
 if(IRValue <= 50){
  go(); 
 }
 else{halt();}
}
