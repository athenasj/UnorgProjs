int i=0;
const int buttonPin =10;
int buttonState=LOW;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;
int val=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(int x=2; x<9;x++){
pinMode(x, OUTPUT);}

pinMode(buttonPin,INPUT);
}
void loop() {
  if(val==1){
    for(int a=0; a<10;a++){
    displayDigit(a);
    delay(1000);  }
    }
    else{
    for(int a=9; a>=0 ;a--){
    displayDigit(a);
    delay(1000); }
    }
    Serial.println("Change switch?");
   val = readButton(buttonPin);

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

void displayDigit(int x){
  switch(x){
    case 0:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    break;

    case 1:
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    break;
    
    case 2:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    break;

    case 3:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    break;
    
    case 4:
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;
    
    case 5:
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;

    case 6:
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;

    case 7:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    break;

    case 8:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;

    case 9:
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;

    default:
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    break;
    }
  
  
  }
