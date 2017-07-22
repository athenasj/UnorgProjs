const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

int buttonState=LOW;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;

int whichbutt=0;
void setup() {
  // put your setup code here, to run once:
  for(int x=6; x<14;x++){
    pinMode(x, OUTPUT);    
    }
  for(int x=2; x<6;x++){
    pinMode(x, INPUT);    
    }
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(readButton(buttonPin1)==1){
            whichbutt=1;
      }
    if(readButton(buttonPin2)==1){
            whichbutt=2;
      }
    if(readButton(buttonPin3)==1){
            whichbutt=3;
      }
    if(readButton(buttonPin4)==1){
            whichbutt=4;
      }
  

}

int readButton(int buttonPin)
{
  int validButtonPress=0;
  int reading=digitalRead(buttonPin);
  if(reading!=lastButtonState)
    lastDebounceTime=millis();
  if((millis()-lastDebounceTime)>debounceDelay)
      if(reading!=buttonState)
        {buttonState=reading;
          if(buttonState==HIGH)
            validButtonPress=1;}
      lastButtonState=reading;
     return validButtonPress;
  }
