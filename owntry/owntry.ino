const int light1 = 12;
const int light2 = 10;
const int buzz = 9;
int freq = 5000;
String wordinput;
char charBuf[50];
int fordot = 100;
int fordash = fordot*3;
int longpause = fordot*2;
String sep = "/";

void setup() {
  // put your setup code here, to run once:
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  pinMode(buzz, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Input your message here:");
  
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
   {
       wordinput = Serial.readString();
       wordinput.toCharArray(charBuf,50);
       Serial.println();
       Serial.println(wordinput);

        for(int i=0; i<wordinput.length(); i++)
      {
          char templet= charBuf[i];
          if('A'>=templet<='Z')
          templet = toLowerCase(templet);
          
          whatchar(templet);
         // if((templet != ' '))
            { Serial.print(sep);
              
            }
      }    
     }
  }

void dot()
  {
  Serial.print(".");
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  tone(buzz, freq, fordot);
  delay(fordot);
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
  noTone(buzz);
  delay(fordot); 
  }
void dash()
  {
  Serial.print("-");  
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  tone(buzz, freq, fordash);
  delay(fordash);
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
  noTone(buzz);
  delay(fordot);   
  }
void pause(){
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
  noTone(buzz);
  delay(fordot);  
  }
void space(){
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
  noTone(buzz);
  delay(longpause);
  Serial.print(" ");
  }
void error(char er){
  Serial.print(er);  
  }
 void whatchar(char templet){
  switch(templet){
         case 'a':
          dot();
          dash();
          pause();
          break;
         case  'b':
          dash();
          dot();
          dot();
          dot();
          pause();
          break;
         case 'c':
          dash();
          dot();
          dash();
          dot();
          pause;
          break;
         case 'd':
          dash();
          dot();
          dot();
          pause();
          break;
         case 'e':
          dot();
          pause();
          break;
         case 'f':
          dot();
          dot();
          dash();
          dot();
          pause();
          break;
         case 'g':
          dash();
          dash();
          dot();
          pause();
          break;
         case'h':
          dot();
          dot();
          dot();
          dot();
          pause();
          break;
         case 'i':
          dot();
          dot();
          pause();
          break;
         case 'j':
          dot();
          dash();
          dash();
          dash();
          pause();
          break;
         case 'k':
          dash();
          dot();
          dash();
          pause();
          break;
         case 'l':
          dot();
          dash();
          dot();
          dot();
          pause();
          break;
         case 'm':
          dash();
          dash();
          pause();
          break;
         case 'n':
          dash();
          dot();
          pause();
          break;
         case 'o':
          dash();
          dash();
          dash();
          pause();
          break;
         case 'p':
          dot();
          dash();
          dash();
          dot();
          pause();
          break;
         case 'q':
          dash();
          dash();
          dot();
          dash();
          pause();
          break;
         case 'r':
          dot();
          dash();
          dot();
          pause();
          break;
         case 's':
          dot();
          dot();
          dot();
          pause();
          break;
         case 't':
          dash();
          pause();
          break;
         case 'u':
          dot();
          dot();
          dash();
          pause();
          break;
         case 'v':
          dot();
          dot();
          dot();
          dash();
          pause();
          break;
         case 'w':
          dot();
          dash();
          dash();
          pause();
          break;
         case 'x':
          dash();
          dot();
          dot();
          dash();
          pause();
          break;
         case 'y':
          dash();
          dot();
          dash();
          dash();
          pause();
          break;
         case 'z':
          dash();
          dash();
          dot();
          dot();
          pause();
          break;
         case ' ':
          space();
          pause();
          break;
         case '0':
          dash();
          dash();
          dash();
          dash();
          pause();
          break;
         case '1':
           dot();
           dash();
           dash();
           dash();
           dash();
           pause();
           break;
         case '2':
           dot();
           dot();
           dash();
           dash();
           dash();
           pause();
           break;
          case '3':
            dot();
            dot();
            dot();
            dash();
            dash();
            pause;
            break;
          case '4':
            dot();
            dot();
            dot();
            dot();
            dash();
            pause;
            break;
           case '5':
            dot();
            dot();
            dot();
            dot();
            dot();
            pause();
            break;
           case '6':
            dash();
            dot();
            dot();
            dot();
            dot();
            pause();
            break;
           case '7':
            dash();
            dash();
            dot();
            dot();
            dot();
            pause();
            break;
           case '8':
            dash();
            dash();
            dash();
            dot();
            dot();
            pause();
            break;
           case '9':
            dash();
            dash();
            dash();
            dash();
            pause();
            break;
           case '.':
            dot();
            dash();
            dot();
            dash();
            dot();
            dash();
            pause();
            break;
           case ',':
            dash();
            dash();
            dot();
            dot();
            dash();
            dash();
            pause();
            break;
           case '?':
            dot();
            dot();
            dash();
            dash();
            dot();
            dot();
            pause();
            break;
           case '!':
            dash();
            dot();
            dash();
            dot();
            dash();
            dash();
            pause();
            break;
            default:
            error(templet);
            pause();
            break;
    }  
  }
