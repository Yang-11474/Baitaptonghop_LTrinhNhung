void setup() {
  for(int i=1;i<11;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  for(int i=1;i<11;i++){
    int num =random(1,11);
    if(num%2==0){
      digitalWrite(i,LOW); 
    }
    else{
      digitalWrite(i,HIGH);
    }
  }
  delay(200);
}
