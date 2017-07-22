void setup() {
  Serial.begin(9600);
}
void sum3(int a, int b, int c){
  int sum = a + b + c;
  Serial.print("The sum is ");
  Serial.println(sum);
  }

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Enter the first number:");
  Serial.flush(); //flush all previous received and transmitted data
  while(!Serial.available()) ;
    int a = Serial.parseInt();
    Serial.print(a);
    Serial.println();
 Serial.print("Enter the second number:");
 Serial.flush(); //flush all previous received and transmitted data
  while(!Serial.available()) ;
    int b = Serial.parseInt();
    Serial.print(b);
    Serial.println();
 Serial.print("Enter the third number:");
 Serial.flush(); //flush all previous received and transmitted data
  while(!Serial.available()) ;
    int c = Serial.parseInt();
    Serial.print(a);
    Serial.println();
    sum3(a, b, c);
}
