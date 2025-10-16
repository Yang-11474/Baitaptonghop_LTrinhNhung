int red=7;
int yellow=6;
int btn=11;
int pre=LOW;
int count=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(btn,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int current=digitalRead(btn);
  if(pre==LOW && current==HIGH){
    count++;
    if(count==1){
      digitalWrite(red,HIGH);
      digitalWrite(yellow,HIGH);
      delay(200);
    
    }
    if(count==2){
      digitalWrite(red,LOW);
      digitalWrite(yellow,LOW);
      delay(200);
    }
    if(count==3){
      digitalWrite(red,LOW);
      digitalWrite(yellow,HIGH);
      delay(200);
    }
    if(count==4){
      digitalWrite(red,HIGH);
      digitalWrite(yellow,LOW);
      delay(200);
      count=0;
    }
    
  }
  pre=current;
}
