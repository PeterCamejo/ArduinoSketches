//int switchstate = 0;
int dtime = 150;
int potVal;
void setup(){
  
  Serial.begin(9600);
  //pinMode(2 , INPUT);
  for(int i = 3; i < 11; i++){
    pinMode( i , OUTPUT);
  }
}

void loop(){
  //switchstate = digitalRead(2);
  potVal = analogRead(A0);
  Serial.println(potVal);
 
  if(potVal < 900){
    for(int i = 3 ; i < 11; i++){
      digitalWrite( i , LOW);
    }
  }
  if(potVal > 1000){
    digitalWrite( 3 , HIGH);
    digitalWrite( 10 , HIGH);
    delay(dtime);
    
    digitalWrite(3 , LOW);
    digitalWrite(10 , LOW);
    digitalWrite(4 , HIGH);
    digitalWrite(9 , HIGH);
    delay(dtime);
    
    digitalWrite(4 , LOW);
    digitalWrite(9 , LOW);
    digitalWrite(5 , HIGH);
    digitalWrite(8 , HIGH);
    delay(dtime);
    
    digitalWrite(5 , LOW);
    digitalWrite(8 , LOW);
    digitalWrite(6 , HIGH);
    digitalWrite(7 , HIGH);
    delay(dtime);
    
    digitalWrite( 6 , LOW);
    digitalWrite( 7 , LOW);
    delay(dtime);
  }
  
  if(potVal > 900 && potVal < 1000){
    digitalWrite(10 , LOW);
    for(int i = 3; i < 11 ; i++){
      if(i == 3){
        digitalWrite( i , HIGH);
      }
      else{
        digitalWrite( i - 1 , LOW);
        digitalWrite( i , HIGH);
      }
      delay(dtime);
    }
  }
  
  if(potVal > 800 && potVal < 900){
    for(int i = 3 ; i < 11 ; i++){
      if(i % 2 ==0){
        digitalWrite( i , HIGH);
      }
      else{
        digitalWrite(i , LOW);
      }
    }
    delay(dtime);
    
    for(int j  = 3 ; j < 11 ; j++){
      delay(dtime);
      if(j % 2 != 0){
        digitalWrite(j , HIGH);
      }
      else{
        digitalWrite(j , LOW);
      }
    }
    delay(dtime);
  }
  if(potVal > 700 && potVal < 800){
    for(int i = 3; i < 11; i+=2){
      digitalWrite(i+1 , LOW);
      digitalWrite( i , HIGH);
    }
    delay(dtime);
    for(int i = 4; i < 11; i+=2){
      digitalWrite(i-1, LOW);
      digitalWrite(i , HIGH);
    }
    delay(dtime);
  }
    
    
         
}
