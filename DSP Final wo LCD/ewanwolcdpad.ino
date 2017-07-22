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
String pin="";
int masC=0;
int regCard;


char mk; //for master card
/*TO DO:
 * FUNCTION FOR KEYPAD
 * FUNCTION FOR REMOVING CARD w/ checker whether card is already in database DONE
 * FUNCTION FOR CHECKING PIN
 * STUDY STEPPER THEN FUNCTION FOR STEPPER
 * LCD LIB PA
 * KUNG MAY TIME PA, ADD NAME TO DATABASE
 */

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);   // Initialize serial communications with the PC
  while (!Serial);
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  Serial.println(F("Welcome! Tap card to initialize."));
  pinMode(lock,OUTPUT);
}
/*
 * Helper routine to dump a byte array as hex values to Serial.
 * IMPORTANT
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
    read_rfid="";
    for (byte i = 0; i < bufferSize; i++) {
        read_rfid=read_rfid + String(buffer[i], HEX);
    }
}
void message(){
  Serial.println("\nWelcome! Tap card to initialize.");
  
  }

void open_lock() {
  //Use this routine when working with Relays and Solenoids etc.
  digitalWrite(lock, HIGH);
  Serial.println("OPEN");
  delay(2000);
  digitalWrite(lock,LOW);  
}

void close_lock() {
  //Use this routine when working with Relays and Solenoids etc.
  digitalWrite(lock, LOW);
  Serial.println("CLOSED");
  delay(2000);
  digitalWrite(lock,LOW);  
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
      Serial.println("Card in database.");
      regCard=1;
      delay(500);      
      break;         
          }
}
}
void addCard(){
  for(int a=0; a<n; a++){
   if(ok_rfid[a]==read_rfid){
      Serial.println("ERROR: Card already in database.");
      delay(500);
      break;         
          }  
        else if (ok_rfid[a]=="0"){
      ok_rfid[a]=read_rfid;
      Serial.print(ok_rfid[a]);
      Serial.println(" is now added");
      delay(500);
      break;
      } else if (a==n-1){
        Serial.println("ERROR: MEMORY FULL!");
        }   
      }
      delay(500);
    } 
  
void removeCard(){
  Serial.println("Tap the card you want to remove.");
  while( ! mfrc522.PICC_IsNewCardPresent());
    while ( ! mfrc522.PICC_ReadCardSerial());
      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.println(read_rfid);
      for(int a=0; a<n; a++){
        if(ok_rfid[a]==read_rfid){
          if(a==0){
            Serial.println("This is the master key. Are you sure?");
            while(!Serial.available());
            mk = Serial.read();
            if(mk=='n'){
              Serial.println("CARD REMOVAL CANCELED.");
              delay(500);
              break;
              }else if(mk!='y'){
                Serial.println("ERROR: INVALID INPUT");
                delay(500);
                }         
            
            }
            ok_rfid[a]="0";
            Serial.println("CARD SUCCESSFULLY REMOVED.");
            delay(500);
            break;         
          }        
        else if (ok_rfid[a]=="0"){
            ok_rfid[a]=read_rfid;
            Serial.print(ok_rfid[a]);
            Serial.println(" is now added");
            delay(500);
            break;
      } else if (a==n-1){
        Serial.println("ERROR: Card not in database.");
        }   
      }
      delay(500);
  
  }  
  


void loop() {
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println(read_rfid);
    
    dataStatus();
    if(state==0) {
      Serial.println("There are no cards. \nDo you want this to be the master card? \ny/n");
      while(!Serial.available());
      mk = Serial.read();
          switch(mk){
            case 'y':
            ok_rfid[0]=read_rfid;
            Serial.println("This card is now the master key.");
            Serial.println("Set pin!"); //when keypad is here, make function
            while(!Serial.available());
            pin=Serial.readString();
            Serial.println(pin);
            break;
            case 'n':
            Serial.println("OK");
            break;            
            default:
            Serial.println("ERROR INPUT!");
            message();
            return;
                        
            }     
      }else if(masC&&regCard==0){
        Serial.println("There is no Master Card. Do you want this to be the Master Card?");
        while(!Serial.available());
        mk=Serial.read();
        if(mk=='n'){
              Serial.println("OKAY");
              delay(500);
              }else if(mk=='y'){
                ok_rfid[0]=read_rfid;
                Serial.println("This card is now the master key.");
                delay(500);
                Serial.println("Set pin!"); //when keypad is here, make function
                while(!Serial.available());
                pin=Serial.readString();
                Serial.println(pin);
                }else{
                Serial.println("INVALID INPUT!");
                return;}
        }
        
    for(int a=0; a<n; a++){
      if (read_rfid==ok_rfid[a]) {
        //for master card
        if(a==0){
          Serial.println("1.Open 2. Add 3. Remove card");
          while(!Serial.available());
          mk = Serial.read();
          switch(mk){
            case '1':
            open_lock();
            break;
            case '2':
            Serial.println("Present desired card.");
            while( ! mfrc522.PICC_IsNewCardPresent());
            while( ! mfrc522.PICC_ReadCardSerial());
            dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
            Serial.println(read_rfid);
            //function to insert new card
            addCard();
            break;
            case '3':
            //create function that will remove card. it will check if it's the master card or normal card
            removeCard();
            break;            
            default:
            Serial.println("ERROR INPUT!");
            message();
            return;
          
          
          }}
        //ok, open the door.
        else
        open_lock();
        break;
        }
      else if(a==n-1)
        {Serial.println("INVALID CARD!");
        close_lock();
        break;}        
    }
    message();
}
