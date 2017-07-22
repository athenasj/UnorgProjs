
int first = 8;
int second = 9;
int result = 10;

int button1 = 2;
int button2 = 3;

boolean but1truon = true;
boolean but1truoff = true;
boolean but2truon = true;
boolean but2truoff = true;

void setup() {

  pinMode(first, OUTPUT);
  pinMode(second, OUTPUT);
  pinMode(result, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);

  Serial.begin(9600);
}


int ledoff=1;
int ledon=0;
void loop() {

  if(but1truon == true && digitalRead(button1) == 1){
    Serial.println("Button 1 is pressed");
    but1truon = false;
    but1truoff = true;
  }
  
  if(digitalRead(button1) == 1){
    digitalWrite(first, HIGH);
  }
  else{
    digitalWrite(first, LOW);
  }

  if(digitalRead(button2) == 1){
    digitalWrite(second, HIGH);
  }
  else{
    digitalWrite(second, LOW);
  }

  if(digitalRead(button1) == 1 && digitalRead(button2) == 1){
    digitalWrite(result, HIGH);
    ledon=1;
    ledoff=0;
    
  }
  else{
    digitalWrite(result, LOW);
    ledon=0;
  }
  
}

