
#include <Arduino.h>                              
#include <wiring_private.h>


String inputString = "";
boolean stringComplete = false ;
int counter = 0; 
unsigned long ms_str=0;

void setup(){
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial.println("Start to Scan");
}
void loop(){
   serialScanerEvent();
   if(stringComplete){
    Serial.println(inputString);
    //initial the value
    inputString = "";
    stringComplete = false ; 
    counter = 0 ;
   }
}
void serialScanerEvent(){
   if (Serial3.available()>0){
    
    char x = (char)Serial3.read();
    inputString +=x;
    counter++;
    ms_str = millis();  
  }
  else{
    if(millis() - ms_str>1000 && counter>0){
      stringComplete = true;
    }
  }


  
}

