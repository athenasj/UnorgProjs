int ledpin=9;
boolean endd=true;
int i=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(endd==true){
    digitalWrite(ledpin, HIGH);
    delay(750);
    digitalWrite(ledpin, LOW);
    delay(750);
    i++;
    if(i==9){
      endd=false;
      }
    
    
    }
  

}
