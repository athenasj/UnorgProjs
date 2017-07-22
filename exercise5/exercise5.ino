int red = 5;
int yellow = 6;
int green = 9;

void setup() {
  // put your setup code here, to run once:

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red,LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(10000);

  digitalWrite(red,LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(1000);

  digitalWrite(red,HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(8000);
}
