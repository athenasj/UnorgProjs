void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Team Number 4\n");
  for(int i=14; i>-1;i--){
    Serial.println(i);
    delay(500);    
    if (i==0)
    Serial.println("End of program");
    }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
