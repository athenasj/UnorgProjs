//This sketch displays the values on a scale of 0-1023 that are generated when you press each key
//They should be similar to the values I have given in the Instructable 
//(allowing for small variations in tolerance of the resistors)




int keyboardPin = 0;    // Analog input pin that the keypad is attached to
 int keyboardValue = A0;   // value read from the keyboard
int x=273;
int y = 1013;
int none =0; //did not enter anywhere

 void setup() {
   // initialize serial communications at 9600 bps:
   Serial.begin(9600); 

 }
 void letter(){
  if (1010<=keyboardValue&&keyboardValue<=1014)
    Serial.println("#");
    else if(823<=keyboardValue&&keyboardValue<=831)
      Serial.println("9");
    else if(704<=keyboardValue&&keyboardValue<=708)
      Serial.println("6");
    else if(605<=keyboardValue&&keyboardValue<=619)
      Serial.println("3");
    else if(502<=keyboardValue&&keyboardValue<=504)
      Serial.println("0");
    else if(457<=keyboardValue&&keyboardValue<=458)
      Serial.println("8");    
    else if(415<=keyboardValue&&keyboardValue<=420)
      Serial.println("5");
    else if(379<=keyboardValue&&keyboardValue<=380)
      Serial.println("2");
    else if(336<=keyboardValue&&keyboardValue<=338)
      Serial.println("*");      
    else if(315<=keyboardValue&&keyboardValue<=316)
      Serial.println("7");
    else if(294<=keyboardValue&&keyboardValue<=296)
      Serial.println("4");
    else if(273<=keyboardValue&&keyboardValue<=278)
      Serial.println("1");
    
   else{none=0;}
 }
  
 void loop() {
   keyboardValue = analogRead(keyboardPin); // read the pot value
   //Serial.println(keyboardValue);
  if(x<keyboardValue&&keyboardValue<y)
 { none=1; 
   letter();
   //Serial.println("in");
   //Serial.println(keyboardValue);      // print the keyboardValueue back to the serial view window on your PC
   if(none)
   delay(200);                }  // wait 1000 milliseconds before the next loop
   else
   delay(50);
 }

  
