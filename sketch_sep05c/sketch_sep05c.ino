int button = 2;

boolean buttrueon = true;
boolean buttrueoff = true;

int counter=0;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);

}

void loop() {

  if(digitalRead(button) == 1){
    delay(600);
    counter++;
    Serial.print("Button is pressed");
    Serial.println(counter);    
  }
  
}
