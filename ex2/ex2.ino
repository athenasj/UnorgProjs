

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

int firstgiven;
int secondgiven;

int answer;

char operand;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
  Serial.begin(9600);
  
}

String container1;
String container;
 //String container2;
char key;
  
void loop(){
   
  Serial.println("Enter first number:");
  for( int i = 0; i < 3; i++){
    key = '\0';
    key = keypad.getKey();
    if(key){
      container1 = key;
      Serial.println(container1);
      container = container + container1;      
    }
    else{
      i--;
    }       
  }

  firstgiven = container.toInt();
  Serial.println(firstgiven);

  Serial.println("Enter second number:");
  container = "";

  for( int i = 0; i < 3; i++){
    key = '\0';
    key = keypad.getKey();
    if(key){
      container1 = key;
      Serial.println(container1);
      container = container + container1;      
    }
    else{
      i--;
    }       
  }

   secondgiven = container.toInt();
   Serial.println(secondgiven);

  
  Serial.println("Enter operand:");
    while(!Serial.available());
    operand = Serial.read();

    finalans(firstgiven, secondgiven, operand);

}

void finalans(int firstgiven, int secondgiven, char operand){
  switch(operand){
    
    case '+':
     answer = firstgiven + secondgiven;
     break;
     
    case '-':
     answer = firstgiven - secondgiven;
     break;

    case '*':
     answer = firstgiven * secondgiven;
     break;

    case '/':
     answer = firstgiven / secondgiven;
     break;
  }

  Serial.println(answer);
}

