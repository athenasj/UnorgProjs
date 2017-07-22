
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(">>>RIGHT TRIANGLE<<<");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();
  Serial.println("Enter the base:");
  while(!Serial.available());
  int x = Serial.parseInt();
  Serial.println(x);
  Serial.flush();
  Serial.println("Enter the height:");
  while(!Serial.available());
  int y = Serial.parseInt();
  Serial.println(y);
  int a = x*x;
  int b = y*y;
  int c = a + b;

  c= sqrt(c);
  Serial.print("The perimeter is ");
  Serial.println(x + y + c);
  float area= 0.5 *x*y;
  
  Serial.print("The area is ");
  Serial.println(area);
  

}
