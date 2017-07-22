///LETS PLAY
int dilay=100;



void setup() {
  // put your setup code here, to run once:
  for(int i=3; i <14; i++)
  pinMode(i, OUTPUT);
  Serial.begin(9600);
  pinMode(2, INPUT);
  Serial.println("The game starts now.");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i =12; i>2; i--){
  int b=i;
  digitalWrite(i, HIGH);
  delay(dilay);
  if ((i==10 && digitalRead(2)==HIGH && digitalRead(11)==LOW)||(i==5&&digitalRead(2)==HIGH&&digitalRead(6)==LOW)){
  dilay = dilay - 50;
  Serial.println(dilay);
  i = 13;
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  } else if(digitalRead(2)==HIGH){
    Serial.println("GAME OVER. TRY AGAIN.");
    Serial.println("1000");
    digitalWrite(i,LOW);
      delay(250);
    digitalWrite(i,HIGH);
     delay(250);
     digitalWrite(i,LOW);
      delay(250);
    digitalWrite(i,HIGH);
     delay(250);
     digitalWrite(i,LOW);
      delay(250);
    digitalWrite(i,HIGH);
     delay(250); 
     digitalWrite(i,LOW);
     delay(250);
     dilay = 300; 
     i=13;
    }
  if (dilay == 50){    
    Serial.println("Well done!");
    dilay = 300;}
  
  digitalWrite(b, LOW);
  }
  
  

  
}
