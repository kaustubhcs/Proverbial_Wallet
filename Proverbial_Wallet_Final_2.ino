
#include <SoftwareSerial.h>

int rx=0;
int tx=1;
int pwm1=12;
int pwm2=4;
int bt_rx=3;
int bt_tx=2;
int mot=6;
int vib=8;
int mag=11;
int val=5;
int led=13;
int viber=7;

int developers_option=0;
int current_status=-1;
int init_current_status=-1;

SoftwareSerial portOne(bt_tx,bt_rx);


void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
 

  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(mot,OUTPUT);
  pinMode(vib,OUTPUT);
  pinMode(mag,OUTPUT);
  pinMode(val,OUTPUT);
  pinMode(viber,OUTPUT);
  pinMode(led,OUTPUT);


  // Start each software serial port
  portOne.begin(9600);

analogWrite(pwm1,255);                   
analogWrite(pwm2,255);                   
 
Serial.write("                                         Welcome to Proverbial Wallet");       
Serial.write("\n"); 
 
 
portOne.write("                                         Welcome to Proverbial Wallet");       
portOne.write("\n"); 
}

void worker(int work)
{

  switch(work)
  {
   
     case 1 :
           if (developers_option)
          {
           portOne.write("WORKER 1 ACTIVATED\nPumping air inside wallet...\n");
           Serial.print("WORKER 1 ACTIVATED\nPumping air inside wallet...\n");       
          }

               digitalWrite(led,HIGH);
               digitalWrite(mot,HIGH);
               digitalWrite(val,HIGH);
               delay(2000);
               digitalWrite(mot,LOW);
               digitalWrite(led,LOW);
               break;
    
    case 2 : 
               if (developers_option)
          {
           portOne.write("WORKER 2 ACTIVATED\nDeflating Wallet...\n");
           Serial.print("WORKER 2 ACTIVATED\nDeflating Wallet...\n");
          }

               digitalWrite(led,HIGH);
               digitalWrite(val,LOW);
               digitalWrite(led,LOW);    
               break;
    
    
    
    case 3 : 
              
           if (developers_option)
          {
           portOne.write("WORKER 3 ACTIVATED\nWithdraw Pattern Activated !\n");
           Serial.print("WORKER 3 ACTIVATED\nWithdraw Pattern Activated !\n");
          }

              digitalWrite(led,HIGH);
    
    
    
for (int wid=0;wid<7;wid++)    
    {
               digitalWrite(vib,HIGH);
               digitalWrite(viber,HIGH);
               delay(250);
               digitalWrite(vib,LOW);
               digitalWrite(viber,LOW);
               delay(50);
               digitalWrite(vib,HIGH);
               digitalWrite(viber,HIGH);
               delay(50);
               digitalWrite(vib,LOW);
               digitalWrite(viber,LOW);
               delay(50);
               digitalWrite(vib,HIGH);
               digitalWrite(viber,HIGH);
               delay(50);
               digitalWrite(vib,LOW);
               digitalWrite(viber,LOW);
               delay(100);
    }
    
               digitalWrite(led,LOW);
               break;
    
 
    case 4 : 
    
    
           if (developers_option)
          {
           portOne.write("WORKER 4 ACTIVATED\nDeposit Pattern Activated !\n");
           Serial.print("WORKER 4 ACTIVATED\nDeposit Pattern Activated !\n");
          }

               digitalWrite(led,HIGH);


for (int dep=0;dep<15;dep++)    
    {
               digitalWrite(vib,HIGH);
               digitalWrite(viber,HIGH);
               delay(100);
               digitalWrite(vib,LOW);
               digitalWrite(viber,LOW);
               delay(100);
    }
    
               digitalWrite(led,LOW);
               break;
  
  
      case 5 : 
           if (developers_option)
          {
           portOne.write("WORKER 5 ACTIVATED\nElectromagnet LOW\n");
           Serial.print("WORKER 5 ACTIVATED\nElectromagnet LOW\n");
          }

                     digitalWrite(led,HIGH);
                      analogWrite(mag,0);
                      delay(10);
                      
               
               digitalWrite(led,LOW);
               break;
               
    case 6 : 
    
           if (developers_option)
          {
           portOne.write("WORKER 6 ACTIVATED\nElectromagnet MEDIUM\n");
           Serial.print("WORKER 6 ACTIVATED\nElectromagnet MEDIUM\n");
          }

                      digitalWrite(led,HIGH);
                      analogWrite(mag,150);
                      delay(10);
                                     
               
               digitalWrite(led,LOW);
               break;
    case 7 : 
    
           if (developers_option)
          {
           portOne.write("WORKER 7 ACTIVATED\nElectromagnet HIGH\n");
           Serial.print("WORKER 7 ACTIVATED\nElectromagnet HIGH\n");
          }

                      digitalWrite(led,HIGH);
                      analogWrite(mag,255);
                      delay(10);
               
               digitalWrite(led,LOW);
               break;

   
  }  
}

void vib_fun(int initial,int final)
{
       if (initial != final)
          {
           if  (initial < final)
               { 
              
                   
                    portOne.write("Cash Deposited\n");
                    Serial.print("Cash Deposited\n"); 
                   
                worker(4);
               }
               
           if (initial > final)
              {
                
                   
                    portOne.write("Cash Withdrawn\n");
                    Serial.print("Cash Withdrawn\n"); 
                   
               worker(3);
              }       
         }
  
}


void loop()
{
  // By default, the last intialized port is listening.
  // when you want to listen on a port, explicitly select it:
  portOne.listen(); 
    
  // while there is data coming in, read it
  // and send to the hardware serial port:
  if (portOne.available() > 0) 
  {
    char inByte = portOne.read();
    Serial.write(inByte);
 
 

      switch(inByte)
      {
       case 'l' :
       
       portOne.write("BALANCE STATUS: POOR");
       portOne.write("\n");
       
       if (current_status != 1 && current_status != 2)
       {
       if (developers_option)
          {
           portOne.write("L1 ACTIVATED\n");
        
          }
       worker(5);
       worker(2);
       worker(7);
       }
       
      
       
       init_current_status = current_status;   
          
       current_status=1;
 
       vib_fun(init_current_status,current_status);
       
       
       break;
      
       case 'L' :
       
       portOne.write("BALANCE STATUS: LOW ON CASH");
       portOne.write("\n");
       
       if (current_status != 1 && current_status != 2)
       {
       if (developers_option)
          {
           portOne.write("L2 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       worker(7);
       }

       init_current_status = current_status;
       current_status=2;
       vib_fun(init_current_status,current_status);
       
       break;
      
       case 'm' :

       portOne.write("BALANCE STATUS: INSUFFICIENT");
       portOne.write("\n");
       

       if (current_status != 3 && current_status != 4)
       {
       if (developers_option)
          {
           portOne.write("M1 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(6);
       }

       
       
       
       
       init_current_status = current_status;
       current_status=3;
       vib_fun(init_current_status,current_status);
       break;
      
       case 'M' :
       
       portOne.write("BALANCE STATUS: SUFFICIENT");
       portOne.write("\n");
       

       if (current_status != 3 && current_status != 4)
       {
       if (developers_option)
          {
           portOne.write("M2 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(6);
       }
       
       
       
       init_current_status = current_status;
       current_status=4;
       vib_fun(init_current_status,current_status);
       break;
      
       case 'h' :
       
       portOne.write("BALANCE STATUS: HIGH ON CASH");
       portOne.write("\n");
       
       
       if (current_status != 5 && current_status != 6)
       {
       if (developers_option)
          {
           portOne.write("H1 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(1);
       worker(1);
       worker(5);
       }

       
       
       
       init_current_status = current_status;
       current_status=5;
       vib_fun(init_current_status,current_status);
       break;
      
       case 'H' :
     
       portOne.write("BALANCE STATUS: RICH");
       portOne.write("\n");
       

       
       if (current_status != 5 && current_status != 6)
       {
       if (developers_option)
          {
           portOne.write("H2 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(1);
       worker(1);
       worker(5);
       }

       
       
       
       init_current_status = current_status;
       current_status=6;
       vib_fun(init_current_status,current_status);
       break;

       case 'd':
       developers_option = 1;
       portOne.write("Developer's Mode Activated !\n");
       break;
       
       case 'e':
       portOne.write("Developer's Mode Deactivated !\n");
       developers_option = 0;
       break;
       
       
       
      portOne.write("Incorrect data !\n");      
      }
 }


  
  if (Serial.available()) 
  {  
    char inByte = Serial.read();
    portOne.write(inByte);
  
   Serial.write(inByte);
   Serial.write("\n\n");
      switch(inByte)
      {
       case 'l' :
       
       Serial.print("BALANCE STATUS: POOR");
       Serial.print("\n");
       
       if (current_status != 1 && current_status != 2)
       {
       if (developers_option)
          {
           Serial.print("L1 ACTIVATED\n");
        
          }
       worker(5);
       worker(2);
       worker(7);
       }
       
      
       
       init_current_status = current_status;   
          
       current_status=1;
 
       vib_fun(init_current_status,current_status);
       
       
       break;
      
       case 'L' :
       
       Serial.print("BALANCE STATUS: LOW ON CASH");
       Serial.print("\n");
       
       if (current_status != 1 && current_status != 2)
       {
       if (developers_option)
          {
           Serial.print("L2 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       worker(7);
       }

       init_current_status = current_status;
       current_status=2;
       vib_fun(init_current_status,current_status);
       
       break;
      
       case 'm' :

       Serial.print("BALANCE STATUS: INSUFFICIENT");
       Serial.print("\n");
       

       if (current_status != 3 && current_status != 4)
       {
       if (developers_option)
          {
           Serial.print("M1 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(6);
       }

       
       
       
       
       init_current_status = current_status;
       current_status=3;
       vib_fun(init_current_status,current_status);
       break;
      
       case 'M' :
       
       Serial.print("BALANCE STATUS: SUFFICIENT");
       Serial.print("\n");
       

       if (current_status != 3 && current_status != 4)
       {
       if (developers_option)
          {
           Serial.print("M2 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(6);
       }
       
       
       
       init_current_status = current_status;
       current_status=4;
       vib_fun(init_current_status,current_status);
       break;
      
       case 'h' :
       
       Serial.print("BALANCE STATUS: HIGH ON CASH");
       Serial.print("\n");
       
       
       if (current_status != 5 && current_status != 6)
       {
       if (developers_option)
          {
           Serial.print("H1 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(1);
       worker(1);
       worker(5);
       }

       
       
       
       init_current_status = current_status;
       current_status=5;
       vib_fun(init_current_status,current_status);
       break;
      
       case 'H' :
     
       Serial.print("BALANCE STATUS: RICH");
       Serial.print("\n");
       

       
       if (current_status != 5 && current_status != 6)
       {
       if (developers_option)
          {
           Serial.print("H2 ACTIVATED\n");
        
          }

       worker(5);
       worker(2);
       delay(3000);
       worker(1);
       worker(1);
       worker(1);
       worker(5);
       }

       
       
       
       init_current_status = current_status;
       current_status=6;
       vib_fun(init_current_status,current_status);
       break;

       case 'd':
       developers_option = 1;
       Serial.print("Developer's Mode Activated !\n");
       break;
       
       case 'e':
       Serial.print("Developer's Mode Deactivated !\n");
       developers_option = 0;
       break;
       
       
       
      default: Serial.print("Incorrect data !\n");      
      }
 }

  

  
}







