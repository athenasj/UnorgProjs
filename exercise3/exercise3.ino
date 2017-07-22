int ledPin=6;

void setup() {
 pinMode(ledPin,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(750);
  digitalWrite(ledPin, LOW);
  delay(750);
}
