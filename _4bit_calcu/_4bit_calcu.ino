
const int buttonPinOne = 2;
const int buttonPinTwo = 3;
const int buttonPinThree = 4;
const int buttonPinFour = 5;
const int led1=6;
const int led2=7;
const int led3=8;
const int led4=9;
const int led5=10;
const int led6=11;
const int led7=12;
const int led8=13;

int buttonState=LOW;
int lastButtonState=LOW;
long lastDebounceTime=0;
long debounceDelay=50;

int bit1=0;
int bit2=0;
int bit3=0;
int bit4=0;
String first="";
String second="";

char oper;
int decone;
int dectwo;



void setup() {
  
  pinMode(led1, OUTPUT);     //RED
  pinMode(led2, OUTPUT);     //GREEN
  pinMode(led3, OUTPUT);     //RED
  pinMode(led4, OUTPUT);     //GREEN
  pinMode(led5, OUTPUT);    //RED
  pinMode(led6, OUTPUT);    //GREEN
  pinMode(led7, OUTPUT);    //RED
  pinMode(led8, OUTPUT);    //GREEN

  pinMode(buttonPinOne, INPUT);      //SWITCH ONE
  pinMode(buttonPinTwo, INPUT);      //SWITCH TWO
  pinMode(buttonPinThree, INPUT);    //SWITCH THREE
  pinMode(buttonPinFour, INPUT);     //SWITCH FOUR

  Serial.begin(9600);

}

void loop() {
  Serial.println("Enter the first 4-bit.");
  delay(500);
  Serial.println("Hold it until.");
  delay(1500);
  
  bit1=digitalRead(2);
  bit2=digitalRead(3);
  bit3=digitalRead(4);
  bit4=digitalRead(5);
  
  Serial.println("Let go.");
  
  first=String(bit1)+String(bit2)+String(bit3)+String(bit4); //The  first input  in String
  decone=(bit1*8)+(bit2*4)+(bit3*2)+(bit4*1);                //The first input in DEC
  Serial.print("You entered: "); 
  Serial.println(first); 
  /*Serial.print("this is decone ");
  Serial.println(decone);*/
  
  delay(2000);

  Serial.println("\n\n");
  Serial.println("Enter the second 4-bit.");
  delay(500);
  Serial.println("Hold it until.");
  delay(1500);
  
  bit1=digitalRead(2);
  bit2=digitalRead(3);
  bit3=digitalRead(4);
  bit4=digitalRead(5);
  
  Serial.println("Let go.");
  
  second=String(bit1)+String(bit2)+String(bit3)+String(bit4); //The  first input  in String
  dectwo=(bit1*8)+(bit2*4)+(bit3*2)+(bit4*1);                //The first input in DEC
  Serial.print("You entered: "); 
  Serial.println(second); 
  /*Serial.print("this is dectwo ");
  Serial.println(dectwo);*/
  
  delay(1000);
  
  Serial.println("Enter your operation.");
  while(!Serial.available());
  oper = Serial.read();
  int answer=calculate(oper, decone, dectwo);
  Serial.print("Your expression is ");
  Serial.print(first);
  Serial.print(oper);
  Serial.print(second);
  Serial.print("=");
  Serial.println(answer,BIN);

    int myNum = answer;
    int zeros = String(myNum,BIN).length();
    String myStr = String(myNum,BIN);
    char charBuf[]={0, 0, 0, 0, 0, 0, 0, 0};
    myStr.toCharArray(charBuf,8);
    int pin;
    if (zeros==1)
    pin = 13;
    if (zeros==2)
    pin = 12;    
    if (zeros==3)
    pin = 11;    
    if (zeros==4)
    pin = 10;    
    if (zeros==5)
    pin = 9;    
    if (zeros==6)
    pin = 8;
    if (zeros==7)
    pin = 7;

    if (zeros==8)
    pin = 6;
    
   for (int i=0; i<zeros; i++) {
    if(charBuf[i]=='1')
    digitalWrite(pin, HIGH);
    else
    digitalWrite(pin,LOW);
    pin++;
    }
         
    Serial.println(myStr);             
     

   Serial.println("Continue? y/n");
   while(!Serial.available());
    if(Serial.read()=='y'){
       for(int i=6; i<14;i++)
      digitalWrite(i,LOW);}
    else while(!Serial.available()){
      for(int i=6; i<14;i++)
      digitalWrite(i, LOW);
      Serial.println();
      
      }
   
  }


int calculate (char oper, int a, int b){
  int answer;
  
  switch(oper){
      case '+':
      answer = a+b;
      Serial.println(answer, 2);
      break;
      
      case '-':
      answer = a-b;      
      Serial.println(answer, 2);
      break;

      case '*':
      answer = a*b;
      Serial.println(answer, 2);
      break;

      case '/':
      answer = a+b;
      Serial.println(answer, 2);
      break;
      
      default:
      Serial.println("Invalid INPUT!");
      break;
      
   }
   return answer;

}
