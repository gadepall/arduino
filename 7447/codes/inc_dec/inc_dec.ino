//Code released under GNU GPL.  Free to use for anything.
//Remove the following  line if you are using the Arduino IDE
#include "Arduino.h"

//Declaring all variables as integers
int Z=1,Y=0,X=0,W=1;
int D,C,B,A;
// the setup function runs once when you press reset or power the board
void setup() {
	//declaring output pins
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  A=0;
  B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);
  
  //Writing data to the output pins
  digitalWrite(2, A); //LSB
  digitalWrite(3, B); 
  digitalWrite(4, C); 
  digitalWrite(5, D); //MSB
}
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
