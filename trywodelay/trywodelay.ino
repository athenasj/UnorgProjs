long prevmili =0;
const int ledpin = 13;
int howlong = 3000;
boolean ledstate;
int ledpin12 = 12;
boolean ledstate1;


void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(12,OUTPUT);

}

void loop() {
  unsigned long curmili = millis();

  if(curmili-prevmili > howlong){
    prevmili=curmili;

       if (ledstate==HIGH){
        ledstate=LOW;        
       }else{
        ledstate=HIGH;
        }
        if (ledstate==HIGH){ledstate1=LOW;}
        else{ledstate1=HIGH;}
            
    
    
    digitalWrite(ledpin, ledstate); 
    digitalWrite(ledpin12, ledstate1);

       
    
    }

}
