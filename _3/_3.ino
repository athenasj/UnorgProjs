void setup() {
 Serial.begin(9600);
 Serial.println("Enter the amount of stars:");
}
int k=1;
void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available());
  int star = Serial.parseInt();
  Serial.println(star);

  for(int i=0; i<star; i++){
    for(int j=0; j<k; j++){
      Serial.print("*");
      }
      k++;
      Serial.println();  
  }
}
