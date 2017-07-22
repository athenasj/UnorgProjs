int x = 0;

const int buttonPin =10;
int buttonState = LOW;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;

void setup() {

    pinMode(buttonPin, INPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT); 

    Serial.begin(9600);
    
}

void loop() {

  display_digit(x);
  if(readButton(buttonPin) == 1){
    Serial.println(x);
    x++;
    Serial.println(x);
    if(x == 10){
      x = 0;}
  }
}

void display_digit(int x){

  for(int i = 2; i < 9; i++){
    digitalWrite(i, HIGH);
    switch(x)
    {
      case 0:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      break;
      case 1: 
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      break;
      case 2:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(8, LOW);
      break;
      case 3:
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(8, LOW);
      break;
      case 4:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
      case 5:
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
      case 6:
      digitalWrite(2, LOW);
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
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      break;
    }
  }
}

int readButton(int buttonPin){

  int validButtonPress = 0;
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState)
    lastDebounceTime = millis();
  if ((millis()- lastDebounceTime) > debounceDelay)
    if (reading != buttonState){
      buttonState = reading;
      if (buttonState == HIGH)
        validButtonPress = 1; 
    }
  lastButtonState = reading;
  return validButtonPress;
}

