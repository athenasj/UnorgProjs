
#include <Keypad.h>

int times = 0;
char container;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {7, 2, 3, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 8, 4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char key = keypad.getKey();

void setup(){
  Serial.begin(9600);
}
  
void loop(){

  if (key != NO_KEY){
    Serial.println(key);
    key = container; 
    key_identifier(times);
    Serial.println("this is" + times);
  }
  
}

void key_identifier(int times){
  if(key = container){
    times++;
  }
}


