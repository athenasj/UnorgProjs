
const int buttonPinOne = 2;
const int buttonPinTwo = 3;
const int buttonPinThree = 4;
const int buttonPinFour = 5;

int buttonState=LOW;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;

void setup() {
  
  pinMode(6, OUTPUT);     //RED
  pinMode(7, OUTPUT);     //GREEN
  pinMode(8, OUTPUT);     //RED
  pinMode(9, OUTPUT);     //GREEN
  pinMode(10, OUTPUT);    //RED
  pinMode(11, OUTPUT);    //GREEN
  pinMode(12, OUTPUT);    //RED
  pinMode(13, OUTPUT);    //GREEN

  pinMode(buttonPinOne, INPUT);      //SWITCH ONE
  pinMode(buttonPinTwo, INPUT);      //SWITCH TWO
  pinMode(buttonPinThree, INPUT);    //SWITCH THREE
  pinMode(buttonPinFour, INPUT);     //SWITCH FOUR

  Serial.begin(9600);

}

void loop() {

  int j = 13;
  int l = 7;
  
  if(digitalRead(buttonPinOne) == 1){
    for(int i = 6; i < 14; i ++){
      digitalWrite( i, HIGH);
      digitalWrite( j, HIGH);
      delay(300);
      digitalWrite( i, LOW);
      digitalWrite( j, LOW);
      
      j--;
      Serial.println("button1");
    }
  }

  if(digitalRead(buttonPinTwo) == 1){
    Serial.println("button2");
    for( int i = 6; i < 13; i += 2){
      digitalWrite( i, HIGH);
      delay(300);
      digitalWrite( i, LOW);
    }
    for( int i = 13; i > 6; i -= 2){
      digitalWrite( i, HIGH);
      delay(300);
      digitalWrite(i, LOW);
    }
  }
  if(digitalRead(buttonPinThree) == 1){
    Serial.println("button3");
    for(int i = 6; i < 13; i++){
      digitalWrite( i, HIGH);
      delay(300);
      digitalWrite(i, LOW);
    }
    for(int i = 13; i > 5; i--){
      digitalWrite( i, HIGH);
      delay(300);
      digitalWrite(i, LOW);
    }
    Serial.println("end of 3");
  }
  if(digitalRead(buttonPinFour) == 1){
    Serial.println("button4");
    for(int i = 6; i < 13; i += 2){
      digitalWrite( i, HIGH);
      digitalWrite( l, HIGH);
      delay(300);
      digitalWrite( i, LOW);
      digitalWrite( l, LOW);
      l += 2;
    }
    for(int i = 12; i > 5; i-=2){
      digitalWrite( i, HIGH);
      digitalWrite( j, HIGH);
      delay(300);
      digitalWrite( i, LOW);
      digitalWrite( j, LOW);
      j -= 2;
    }
  }
  
}



int readButton(int buttonPin)
{
  Serial.println("this \n\n\n\n");
int validButtonPress=0;
int  reading=digitalRead(buttonPin);
  if(reading!=lastButtonState)
    lastDebounceTime=millis();
  if((millis()-lastDebounceTime)>debounceDelay)
      if(reading!=buttonState)
        {buttonState=reading;
          if(buttonState==HIGH)
            validButtonPress=1;
            }
      lastButtonState=reading;
      Serial.println(validButtonPress);
     return validButtonPress;
  }
