
#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

int lock =2;
String read_rfid;
String  ok_rfid[10]={"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};//"database"
int n = sizeof(ok_rfid)/sizeof(String);
int state;
String pin=""; //pin set
String pinCheck="";
int pinStatus=0;
int masC=0;
int regCard;
String mk; //for master card
char mk1;
/*TO DO:
 * STUDY STEPPER THEN FUNCTION FOR STEPPER
 * LCD LIB PA
 * KUNG MAY TIME PA, ADD NAME TO DATABASE
 */

int keyboardPin = 0;    // Analog input pin that the keypad is attached to
int keyboardValue = A0;   // value read from the keyboard

int none =0; //did not enter anywhere

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  lcd.begin(16,2);
  lcd.clear();
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  //Serial.println(("Welcome! Tap card to initialize."));
  lcd.setCursor(0,0);
  lcd.print("Welcome!");  
  lcd.setCursor(0,1);
  lcd.print("Tap card.");
  pinMode(lock,OUTPUT);
}

void dump_byte_array(byte *buffer, byte bufferSize) {
    read_rfid="";
    for (byte i = 0; i < bufferSize; i++) {
        read_rfid=read_rfid + String(buffer[i], HEX);
    }
}
void letter(){
  none=0;
  keyboardValue = analogRead(keyboardPin); // read the pot value
   //Serial.println(keyboardValue);
  if(273<keyboardValue&&keyboardValue<1014)
 { none=1; 
   if (1010<=keyboardValue&&keyboardValue<=1014)
      {//Serial.println("#");
      mk="9";}
    else if(823<=keyboardValue&&keyboardValue<=831)
      {//Serial.println("9");
      mk="9";}
    else if(704<=keyboardValue&&keyboardValue<=708)
      {//Serial.println("6");
      mk="6";}
    else if(605<=keyboardValue&&keyboardValue<=619)
      {//Serial.println("3");
      mk="3";}
    else if(502<=keyboardValue&&keyboardValue<=504)
      {//Serial.println("0");
      mk="0";}
    else if(457<=keyboardValue&&keyboardValue<=458)
      {//Serial.println("8");    
      mk="8";}
    else if(415<=keyboardValue&&keyboardValue<=420)
      {//Serial.println("5");
      mk="5";}
    else if(379<=keyboardValue&&keyboardValue<=380)
      {//Serial.println("2");
      mk="2";}
    else if(336<=keyboardValue&&keyboardValue<=338)
      {//Serial.println("*");     
      mk="*";}
    else if(315<=keyboardValue&&keyboardValue<=316)
      {//Serial.println("7");
      mk="7";}
    else if(294<=keyboardValue&&keyboardValue<=296)
      {//Serial.println("4");
      mk="4";}
    else if(273<=keyboardValue&&keyboardValue<=278)
      {//Serial.println("1");
      mk="1";}    
   else{none=0;}
   
   if(none){
   delay(200);
   return;} } // wait 1000 milliseconds before the next loop
   
   if(none==0)
   {delay(50);
   //Serial.println("in");
   mk="";
   letter();}
 }
void message(){
  //Serial.println("\nWelcome! Tap card to initialize.");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome!");  
  lcd.setCursor(0,1);
  lcd.print("Tap card.");
  
  }

void open_lock() {
  //Use this routine when working with Relays and Solenoids etc.
  digitalWrite(lock, HIGH);
  //Serial.println("OPEN");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ACCESS GRANTED!");
  delay(2000);
  digitalWrite(lock,LOW);  
}

void close_lock() {
  //Use this routine when working with Relays and Solenoids etc.
  digitalWrite(lock, LOW);
  //Serial.println("CLOSED");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ACCESS DENIED!");
  digitalWrite(lock,LOW);
  delay(2000);
    
}

void dataStatus(){  
  state = 0; //card data is empty
  regCard=0;//card is not registered
   masC=0;//there is mk
   
  for(int a=0; a<n; a++){
    if (ok_rfid[a]!="0"){
      state=1; //means there is data
      break;
      }
    }
    if(ok_rfid[0]=="0")
      masC=1; 
 for(int a=0; a<n; a++){
   if(ok_rfid[a]==read_rfid){
      //Serial.println("Card in database.");
      regCard=1;
      delay(500);      
      break;         
          }
}
}
void addCard(){
  //Serial.println("Present desired card.");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Present card.");
            while( ! mfrc522.PICC_IsNewCardPresent());
            while( ! mfrc522.PICC_ReadCardSerial());
            dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
            //Serial.println(read_rfid);
  for(int a=0; a<n; a++){
   if(ok_rfid[a]==read_rfid){
      //Serial.println("ERROR: Card already in database.");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ERROR: Card");
      lcd.setCursor(0,1);
      lcd.print("in database!");
      delay(1000);
      break;         
          }  
        else if (ok_rfid[a]=="0"){
      ok_rfid[a]=read_rfid;
      //Serial.print(ok_rfid[a]);
      //Serial.println(" is now added");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Card is added.");
      delay(1000);
      break;
      } else if (a==n-1){
        //Serial.println("ERROR: MEMORY FULL!");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("ERROR: MEMORY   ");
      lcd.setCursor(0,1);
      lcd.print("FULL.           ");
      delay(1000);
      break;
        }   
      }
      delay(500);
    } 
  
void removeCard(){
  //Serial.println("Tap the card you want to remove.");
  lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tap card to");
      lcd.setCursor(0,1);
      lcd.print("remove.");
    while( ! mfrc522.PICC_IsNewCardPresent());
    while ( ! mfrc522.PICC_ReadCardSerial());
      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
      //Serial.println(read_rfid);
      for(int a=0; a<n; a++){
        if(ok_rfid[a]==read_rfid){
          if(a==0){
            //Serial.println("This is the master key. Are you sure?");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("MASTER KEY.");
            lcd.setCursor(0,1);
            lcd.print("Sure?");
            letter();
            if(mk=="2"){
              Serial.println("CARD REMOVAL CANCELED.");
              lcd.clear();
              lcd.setCursor(0,0);
            lcd.print("CARD REMOVAL");
            lcd.setCursor(0,1);
            lcd.print("CANCELLED");
              delay(1000);
              break;
              }else if(mk!="1"){
                //Serial.println("ERROR: INVALID INPUT");
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("ERROR:");
                lcd.setCursor(0,1);
                lcd.print("WRONG INPUT.");
                delay(1000);
                break;
                }         
            
            }
            ok_rfid[a]="0";
            pin="";
            //Serial.println("CARD SUCCESSFULLY REMOVED.");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("CARD REMOVAL");
            lcd.setCursor(0,1);
            lcd.print("SUCCESS");
            delay(1000);
            break;         
          } else if (a==n-1){
        //Serial.println("ERROR: Card not in database.");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ERROR: Card not");
            lcd.setCursor(0,1);
            lcd.print("found.");
            delay(1000);
        }   
      }
      delay(500);
  
  }

void checkPin(){
            //Serial.println("Input valid pin:"); //when keypad is here, make function
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("INPUT VALID PIN:");
            pinStatus=0;
            pinCheck="";
            
                int q=0;
            while(pinCheck.length()<4){
                letter();
                if(mk!=""){
                pinCheck=pinCheck+mk;
                lcd.setCursor(q++,1);
                lcd.print("*");}                
                }
            //Serial.println(pinCheck);
           if(pinCheck==pin)
            {pinStatus=1; 
           // Serial.println("PIN ACCEPTED.");
            lcd.setCursor(0,0);
            lcd.print("PIN ACCEPTED    ");
            lcd.setCursor(0,1);
            lcd.print("                ");
            delay(1000);}
  }
  


void loop() {
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    //Serial.println(read_rfid);
    
    dataStatus();
    if(state==0) {
      Serial.println("There are no cards. \nSet this to master card?");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("NO CARDS. Make");
            lcd.setCursor(0,1);
            lcd.print("this master card?");            
            letter();
            if(mk=="1"){
            ok_rfid[0]=read_rfid;
            //Serial.println("This card is now the master key.");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("This is now the ");
            lcd.setCursor(0,1);
            lcd.print("Master Key.");
            delay(1500);
            Serial.println("Set pin!"); //when keypad is here, make function
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("SET PIN:");
            int z=0;
            while(pin.length()<4){
                letter();
                if(mk!=""){
                pin=pin+mk;
                lcd.setCursor(z++,1);
                lcd.print("*");}                
                }
            Serial.println(pin);
            }
            else if(mk=="2"){
            //Serial.println("OK");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("OKAY");
            delay(1500);
             }          
            else{
            Serial.println("ERROR INPUT!");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("INVALID INPUT");
            delay(1500);
            message();
            }
           
      }else if(masC&&regCard==0){
        //Serial.println("There is no Master Card. Do you want this to be the Master Card?");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("There's no MC.");
            lcd.setCursor(0,1);
            lcd.print("Make this MC?");
            letter();
        if(mk=="2"){
              //Serial.println("OKAY");
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("OKAY");
              delay(1000);
              }else if(mk=="1"){
                ok_rfid[0]=read_rfid;
                Serial.println("This card is now the master key.");
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("This is now the");
                lcd.setCursor(0,1);
                lcd.print("master card.");
                delay(1500);
                //Serial.println("Set pin!"); //when keypad is here, make function
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("SET PIN:");
                int v=0;
                while(pin.length()<4){
                letter();
                if(mk!=""){
                pin=pin+mk;
                lcd.setCursor(v++,1);
                lcd.print("*");}                
                }
                //Serial.println(pin);
                }else{
                //Serial.println("INVALID INPUT!");
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("INVALID INPUT!");
                delay(1500);
                message();
                return;}
        }
        
    for(int a=0; a<n; a++){
      if (read_rfid==ok_rfid[a]) {
        //for master card
        if(a==0){
          //Serial.println("1.Open 2. Add 3. Remove card");
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("HELLO MC HOLDER.");
          lcd.setCursor(0,1);
          lcd.print("Open Add  Remove");
          letter();
            if(mk== "1")
            open_lock();            
            else if(mk=="2"){            
            checkPin();
            
              if(pinStatus)
                addCard();
              else
            { //Serial.println("ERROR PIN!");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ERROR PIN!");
            delay(1000);}
            break;            
            }
            
            else if(mk=="3")
            {//create function that will remove card. it will check if it's the master card or normal card
            checkPin();
            if(pinStatus)
            removeCard();
            else{
              lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ERROR PIN!");
            delay(1000);}
            break;  }          
            else
            {//Serial.println("ERROR INPUT!");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("ERROR INPUT!");
            message();
            return;}
          }
        //ok, open the door.
        else
        open_lock();
        break;
        }
      else if(a==n-1)
        {//Serial.println("INVALID CARD!");
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("INVALID CARD!");
            close_lock();
             break;}        
    }
    message();
}
