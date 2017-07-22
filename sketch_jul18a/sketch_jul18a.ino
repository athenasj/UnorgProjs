
int dela=1000;
unsigned long prevmil =0;
int stat=LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentmil=millis();
  
  if(currentmil-prevmil>=dela){
    prevmil=currentmil;
    
      if(stat == HIGH){
        stat=LOW;}
        else {
        stat=HIGH;}
        
        digitalWrite(13, stat);
    }

    
}
