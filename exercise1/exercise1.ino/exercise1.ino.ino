int x;
boolean check = true;

void setup() {
  Serial.begin (9600);
  
}

void loop() {
  while(!Serial.available());
  x = Serial.parseInt();
  

    while(check==true){
    Serial.println(x++);
    delay(1000);
      if(x==10)
        x=0;
    }
  }
  


