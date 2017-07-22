

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {7, 2, 3, 5}; 
byte colPins[COLS] = {6, 8, 4};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
  Serial.begin(9600);
  
}

int x=1;
void loop(){
  if(x==1){
    Serial.println("Your input was:");
  x=0;
  }
    char key = keypad.getKey();    
      
      if(key){
      Serial.println(key);
      key = '\0';
      x=1;}
    
    
  }

  

