int first=6;
int second =5;

void setup() {
  // put your setup code here, to run once:
  pinMode(first, OUTPUT);
  pinMode(second, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(first, HIGH);
  digitalWrite(second, LOW);
  delay(750);

  digitalWrite(first, LOW);
  digitalWrite(second, HIGH);
  delay(750);
 
}
