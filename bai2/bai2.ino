
int denDo[]={11,8,5,2};
int denVang[]={12,9,6,3};
int denXanh[]={13,10,7,4};
void setup() {
  for(int i=2;i<14;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  digitalWrite(denXanh[0],HIGH);
  digitalWrite(denXanh[2],HIGH);
  digitalWrite(denDo[1],HIGH);
  digitalWrite(denDo[3],HIGH);
  delay(2000);

  digitalWrite(denXanh[0],LOW);
  digitalWrite(denXanh[2],LOW);
  digitalWrite(denVang[1],HIGH);
  digitalWrite(denVang[3],HIGH);
  delay(500);

  digitalWrite(denVang[1],LOW);
  digitalWrite(denVang[3],LOW);
  digitalWrite(denDo[0],HIGH);
  digitalWrite(denDo[2],HIGH);


  digitalWrite(denDo[1],LOW);
  digitalWrite(denDo[3],LOW);
  digitalWrite(denXanh[1],HIGH);
  digitalWrite(denXanh[3],HIGH);
  delay(2000);

  digitalWrite(denXanh[1],LOW);
  digitalWrite(denXanh[3],LOW);
  digitalWrite(denVang[0],HIGH);
  digitalWrite(denVang[2],HIGH);
  delay(500);

  digitalWrite(denVang[0],LOW);
  digitalWrite(denVang[2],LOW);
  digitalWrite(denDo[1],HIGH);
  digitalWrite(denDo[3],HIGH);

  digitalWrite(denDo[0],LOW);
  digitalWrite(denDo[2],LOW);

}