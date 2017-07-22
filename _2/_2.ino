
char hey;
int first;
int second;
String one;
unsigned long sum;
long difference;
unsigned long product;
unsigned long quotient;

void menu(){
  Serial.print("<<<MENU>>> \n 1-ADD \n 2-SUBTRACT \n 3-MULTIPLY \n 4-DIVIDE \n\n");
}
int ferst(){  
  Serial.println("Enter first number:");
  Serial.flush(); //flush all previous received and transmitted data
  while(!Serial.available()) ;
    one = Serial.readString();
       int fone = one.toInt();
       Serial.println(fone);
    return fone;
  }
int sekend(){  
  Serial.println("Enter second number:");
  Serial.flush(); //flush all previous received and transmitted data
  while(!Serial.available()) ;
    one = Serial.readString(); 
    int fone = one.toInt();
     Serial.println(fone);
    return fone;
  }
void cont(){
  Serial.println(">>>>>Do you want to continue?<<<<<\nY/N?\n");
  Serial.flush(); //flush all previous received and transmitted data
  while(!Serial.available());
  char con = Serial.read();
  switch(con){
    case 'y':
    menu();
    break;
    case 'n':
    for(int x=0;x<20;x++){
      Serial.println();
      }
    break;
    default:
    Serial.println("Invalid input!");
    cont();
    break;    
    }
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  menu();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()>0)
 { hey = Serial.read();
  Serial.println(hey);
  switch(hey){
    case '1':
    first =ferst();
    second = sekend();
    sum = first + second;
    Serial.print("The sum is ");
    Serial.println(sum);
    Serial.println();
    cont();
    break;   
    case '2':
    first =ferst();
    second = sekend();
    difference = first-second;
    Serial.print("The difference is ");
    Serial.println(difference);
    Serial.println();
    cont();
    break;
    case '3':
    first =ferst();
    second = sekend();
    product = first*second;
    Serial.print("The product is ");
    Serial.println(product);
    Serial.println();
    cont();
    break;
    case'4':
    first =ferst();
    second = sekend();
    quotient = first/second;
    Serial.print("The quotient is ");
    Serial.println(quotient);
    Serial.println();
    cont();
    break;
    default:
    Serial.println("INVALID INPUT!");
    menu();
    break;
    }
  }
}
