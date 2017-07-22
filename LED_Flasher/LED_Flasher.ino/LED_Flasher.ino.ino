
const int dlay = 900;
const int erval =100;
void setup() {
  
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);

}

void loop() {
  for(int i = 1; i <= 8; i++){
  digitalWrite(i, HIGH);
  delay(dlay -(erval*i));         
  digitalWrite(i, LOW);
  }
  for(int a = 8; a >= 1; a--){
  digitalWrite(a, HIGH);   
  delay(dlay-(erval*a));             
  digitalWrite(a, LOW);   
  }}
  
