
#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library with the numbers of the interface pins rw en d4-d7
LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'.','a','d'},
  {'g','j','m'},
  {'p','t','w'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {7, 2, 3, 5}; 
byte colPins[COLS] = {6, 8, 4};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

/*
 * MAKE MODES (*)
 * MODE 1 = LETTER & NUMBERS
 * MODE 2 = CAPS LOCK
 * MODE 3 = DELETE (#) & ARROW KEYS
 * 
 * 0 FOR 0 AND SPACE  
 *
 *FIND WAY TO SHOW BLINK OF CURSOR
*/
/*DONE SO FAR:
 *ONE CHARACTER DELETE
 *SMALL LETTERS & FEW CHARACTERS
 * 
*/
int curx=0; //cursor
int cury=0; //cursor
int pres=1;
int perpress=800;
unsigned long prevmilli;
char prevkey='~';
int for5 =0;    //FOR 7 & 9
int dontadd=0;
int mode=1;


void setup(){
  Serial.begin(9600);
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("INITIALIZING");
  lcd.setCursor(0,1);
  lcd.print("KEYPAD...");
  delay(5000);
  lcd.clear();
  //lcd.setCursor(curx, cury);
}
  
void loop(){
  if(curx==15&&cury==0&&prevkey!='~')
    {curx=0;
    cury=1;
    dontadd=1;}
  if(curx==15&&cury==1)
    {curx=0;
    cury=0;}
  if(curx<=0&&cury==0&&prevkey=='~')
    {curx=0;
    cury=0;
    prevkey='~';}
   if(curx<=0&&cury==1&&prevkey=='~')
    {curx=16;
    cury=0;
    prevkey='~';}
  lcd.setCursor(curx, cury);
  lcd.cursor();
  char key = keypad.getKey();
          
  if (key){

                if(mode==1||mode==2){
                    if (key!=prevkey)                                                 //ALGO FOR LAST KEY AND MODE 1
                            {if(prevkey!='~'||prevkey=='*')
                                if(dontadd==0)
                                    curx++;
                                    else dontadd=0;
                             
                                    pres=1;}
                    else{ pres++;
                              if (pres>4&&millis()-prevmilli<perpress&&for5==0)
                                       pres=1;
                                                                             //MAKE CHECKER FOR PQRS7 & WXYZ9
                             else if (pres>5&&millis()-prevmilli<perpress)
                                       {pres=1;   
                                       for5=0;
                                       }
                             else if(millis()-prevmilli>perpress)
                                       {pres=1;
                                       curx++;
                                       }
                             
                         }}                                                 //END OF LAST KEY ALGO  
    //Serial.println(key);
    if (mode==1){
    switch(key){
      case '*':
        {mode=2;
         pres=1;
         prevkey='*';
         curx--;
        break;
        }
      case 'a':                                                           //START OF BUTTON a
      {prevkey='a';
       if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('a');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('b');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('c');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('2');
          prevmilli=millis();}
        }  
      break;}                                                               //END OF BUTTON a

          case 'd':                                                           //START OF BUTTON d
      {prevkey='d';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('d');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('e');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('f');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('3');
          prevmilli=millis();}
        }
      break;}                                                               //END OF BUTTON d

        case 'g':                                                           //START OF BUTTON g
      {prevkey='g';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('g');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('h');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('i');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('4');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON g

        case 'j':                                                           //START OF BUTTON j
      {prevkey='j';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('j');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('k');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('l');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('5');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON j

        case 'm':                                                           //START OF BUTTON m
      {prevkey='m';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('m');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('n');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('o');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('6');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON m

        case 'p':                                                           //START OF BUTTON p
      {prevkey='p';                                                         //FOR TESTING PA
       for5=1;
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('p');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('q');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('r');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('s');
          prevmilli=millis();}
          
       else if (pres==5){
          lcd.setCursor(curx,cury);
          lcd.print('7');
          prevmilli=millis();}                                              //FOR TESTING PA
        }         
      break;}                                                               //END OF BUTTON p

      case 't':                                                           //START OF BUTTON t
      {prevkey='t';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('t');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('u');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('v');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('8');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON t

       case 'w':                                                           //START OF BUTTON w
      {prevkey='w';                                                         //FOR TESTING PA
       for5=1;
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('w');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('x');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('y');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('z');
          prevmilli=millis();}
          
       else if (pres==5){
          lcd.setCursor(curx,cury);
          lcd.print('9');
          prevmilli=millis();}                                              //FOR TESTING PA
        }         
      break;}                                                               //END OF BUTTON w

    case '0':                                                           //START OF BUTTON 0
      {prevkey='0';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print(' ');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('0');
          /*curx++;
          lcd.setCursor(curx,cury);*/
          }
        }         
      break;}                                                               //END OF BUTTON 0

       case '.':                                                            //START OF BUTTON 1
      {prevkey='.';                                                         //FOR TESTING PA
       for5=1;
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('.');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print(',');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('?');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('!');
          prevmilli=millis();}
          
       else if (pres==5){
          lcd.setCursor(curx,cury);
          lcd.print('1');
          prevmilli=millis();}                                              //FOR TESTING PA
        }         
      break;}                                                               //END OF BUTTON 1
       
        case '#':                                                           //START OF BUTTON #
      {prevkey='~';
        
      {if(curx<0&&cury==1)
        {cury=0;
          curx=16;}
        curx--;
      lcd.setCursor(curx,cury);
      lcd.print(' ');
      prevmilli=millis();
      }    
      break; }                                                              //END OF BUTTON #      

        
        default:
          break;}                                                           //END FOR SMALL LETTERS    
      }
     
     
     
     
     
    else if (mode==2){                                                         // FOR MODE 2
    switch(key){
      case '*':
        {mode=3;
         pres=1;
         prevkey='*';
         curx--;
         break;
        }
      case 'a':                                                           //START OF BUTTON a
      {prevkey='a';
       if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('A');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('B');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('C');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('2');
          prevmilli=millis();}
        }  
      break;}                                                               //END OF BUTTON a

          case 'd':                                                           //START OF BUTTON d
      {prevkey='d';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('D');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('E');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('F');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('3');
          prevmilli=millis();}
        }
      break;}                                                               //END OF BUTTON d

        case 'g':                                                           //START OF BUTTON g
      {prevkey='g';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('G');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('H');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('I');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('4');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON g

        case 'j':                                                           //START OF BUTTON j
      {prevkey='j';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('J');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('K');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('L');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('5');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON j

        case 'm':                                                           //START OF BUTTON m
      {prevkey='m';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('M');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('N');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('O');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('6');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON m

        case 'p':                                                           //START OF BUTTON p
      {prevkey='p';                                                         //FOR TESTING PA
       for5=1;
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('P');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('Q');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('R');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('S');
          prevmilli=millis();}
          
       else if (pres==5){
          lcd.setCursor(curx,cury);
          lcd.print('7');
          prevmilli=millis();}                                              //FOR TESTING PA
        }         
      break;}                                                               //END OF BUTTON p

      case 't':                                                           //START OF BUTTON t
      {prevkey='t';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('T');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('U');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('W');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('8');
          prevmilli=millis();}
        }         
      break;}                                                               //END OF BUTTON t

       case 'w':                                                           //START OF BUTTON w
      {prevkey='w';                                                         //FOR TESTING PA
       for5=1;
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('W');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('X');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('Y');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('Z');
          prevmilli=millis();}
          
       else if (pres==5){
          lcd.setCursor(curx,cury);
          lcd.print('9');
          prevmilli=millis();}                                              //FOR TESTING PA
        }         
      break;}                                                               //END OF BUTTON w

    case '0':                                                           //START OF BUTTON 0
      {prevkey='0';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print(' ');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('0');
          }
        }         
      break;}                                                               //END OF BUTTON 0

       case '.':                                                            //START OF BUTTON 1
      {prevkey='.';                                                         //FOR TESTING PA
       for5=1;
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print('.');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print(',');
          prevmilli=millis();
          }
        
        else if (pres==3){
          lcd.setCursor(curx,cury);
          lcd.print('?');
          prevmilli=millis();
          }

       else if (pres==4){
          lcd.setCursor(curx,cury);
          lcd.print('!');
          prevmilli=millis();}
          
       else if (pres==5){
          lcd.setCursor(curx,cury);
          lcd.print('1');
          prevmilli=millis();}                                              //FOR TESTING PA
        }         
      break;}                                                               //END OF BUTTON 1
       
        case '#':                                                           //START OF BUTTON #
      {prevkey='~';
        
      {if(curx<0&&cury==1)
        {cury=0;
          curx=16;}
        curx--;
      lcd.setCursor(curx,cury);
      lcd.print(' ');
      prevmilli=millis();
      }    
      break; }                                                              //END OF BUTTON #      

        
        default:
          break;}                                                           //END FOR SMALL LETTERS    
      }

      else if (mode==3){
    switch(key){
      case '*':
        {mode=1;
         pres=1;
         prevkey='*';
         lcd.setCursor(curx,cury);
        break;
        }
      case 'a':                                                           //START OF BUTTON up
      {{if(cury==0)
        cury=1;
        else if(cury==1)
        cury=0;
      lcd.setCursor(curx,cury);
      lcd.cursor();
      
      }         
      break;}                                                              //END OF BUTTON up



        case 'g':                                                           //START OF BUTTON left
      {{if(curx<16)
        curx--;
        if(curx<0)
        curx=15;
      lcd.setCursor(curx,cury);
      lcd.cursor();
      
      }         
      break;}                                                               //END OF BUTTON left

        case 'm':                                                           //START OF BUTTON right
      {{if(curx>=0)
        curx++;
        if(curx==16)
        curx=0;
      lcd.setCursor(curx,cury);
      lcd.cursor();
      
      }         
      break;}                                                               //END OF BUTTON right



      case 't':                                                           //START OF BUTTON down
      {if(cury==0)
        cury++;
        else if(cury==1)
        cury--;
      lcd.setCursor(curx,cury);
      lcd.cursor();
      
      }             
      break;                                                              //END OF BUTTON down



    case '0':                                                           //START OF BUTTON 0
      {prevkey='0';
        if(pres==1)
      {
      lcd.setCursor(curx,cury);
      lcd.print(' ');
      prevmilli=millis();
      }
      else if(millis()-prevmilli<perpress&&pres>1)
        {if (pres==2){
          lcd.setCursor(curx,cury);
          lcd.print('0');
          /*curx++;
          lcd.setCursor(curx,cury);*/
          }
        }         
      break;}                                                               //END OF BUTTON 0

      
        case '#':                                                           //START OF BUTTON #
      {prevkey='~';
      lcd.setCursor(curx,cury);
      lcd.print(' ');
      
      }    
      break;                                                               //END OF BUTTON #      

        
        default:
          break;}                                                           //END FOR SMALL LETTERS    
      }

      
    }

      
  /* 
   * ADD ALGO HERE PAG DI KA NA TINATAMAD
   * 
   * IMPORTANT: ALSO ADD ALGO FOR IF PRESSED TWO TIMES TURN 2,8,4,6 INTO ARROW KEYS
   * 1 FOR DELETE
   * 
   * 0 FOR 0 AND SPACE
   * 
   * For * = * CAPITAL SMALL
   */
  /*else{
    Serial.println("invalid key");
    
    }*/
}
