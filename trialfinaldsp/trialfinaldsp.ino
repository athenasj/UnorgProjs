#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

int cards[7][5];
int serNum[5];
int* presCard;
int firstcard=0;

boolean access=false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}
int* passNum(){
  int* kard;
  if(rfid.readCardSerial()){
    for(int a=0; a<6;a++){
      kard[a]=rfid.serNum[a];
      Serial.print(kard[a]);
      Serial.print(" ");
      }   
    }Serial.println();
    return kard;
  }
boolean checkCard(int presCard[]){
  boolean state=false;
  
  for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(presCard[i] != cards[x][i]) {
                      state = false;
                  } else {
                      state = true;
                  }
              }
   if(state) break;
            }
            return state;           
        }  


void loop() {
  // put your main code here, to run repeatedly:
  
  if(rfid.isCard()){
    presCard = passNum();
    
   if (firstcard==0)
   {
    Serial.println("Do you want this to be the master key?\ny/n");
    while(!Serial.available());
    char mk=Serial.read();
    if(mk=='y'){
      for(int a=0; a<6;a++){
      cards[0][a]=presCard[a];}
      Serial.println("This key is now the master key");
      firstcard=1;
      
    }else if(mk=='n'){      
      Serial.println("Requires master key before entrance!");}
      else{
      Serial.println("Wrong input!");
      return;      
      }
   }
   
    access = checkCard(presCard);
    if(access&&cards[0][4]==presCard[4])
        Serial.println("Choose what to do: 1. Open Door 2. Grant Access 3.Remove Master status");
        while(!Serial.available());
        char dowhat=Serial.read();
        switch(dowhat){
          case '1':
          digitalWrite(7,HIGH);
          delay(500);
          digitalWrite(7,LOW);
          break;
          case '2':
          Serial.println("Place other card");
          delay(3000);
          
          if(rfid.readCardSerial()){
            for(int a=0; a<6;a++){
             cards[1][a]=rfid.serNum[a];}   
    }         
              break;
       }
     

  Serial.println(access);
  delay(500);
  
  }

rfid.halt();
}
