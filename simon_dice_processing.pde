/**
 * Simple Read
 * 
 * Read data from the serial port and change the color of a rectangle
 * when a switch connected to a Wiring or Arduino board is pressed and released.
 * This example works with the Wiring / Arduino program that follows below.
 */


import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port
String s;

void setup() 
{
  size(200, 300);
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw()
{
  if ( myPort.available() > 0) {  // If data is available\,
    val = myPort.read();         // read it and store it in val
  }
  
  
  background(255);             // Set background to white
  if (val == 0) {              // If the serial value is 0,
    s = "";
    textSize(32);
    text(s,60,250);
    ellipse(100,100,100,100);
    fill(255);
  } 
  else if(val==7) {        
    s = "Good!!";
    textSize(32);
    text(s,60,250);
    rect(50,50,100,100);
    fill(0,0,255);         
   
  }else if(val==6) {        
    s = "Keep Trying!";
    textSize(32);
    text(s,0,250);
    rect(50,50,100,100);
    fill(255,0,0);         
   
  }else if(val==5){
    s = "Sequence";
    textSize(32);
    text(s,40,250);
    ellipse(100,100,100,100);
    fill(0,255,0);  
  }
  else if(val==4){
    s = "Sequence";
    textSize(32);
    text(s,40,250);
    ellipse(100,100,100,100);
    fill(255,0,0);  
  }
  else if(val==3){
    s = "Sequence";
    textSize(32);
    text(s,40,250);
    ellipse(100,100,100,100);
    fill(255,255,0);  
  }
  else if(val==2){
    s = "Sequence";
    textSize(32);
    text(s,40,250);
    ellipse(100,100,100,100);
    fill(0,0,255);  
  }else if(val==8) {        
    s = "Go!!";
    textSize(32);
    text(s,60,250);
    rect(50,50,100,100);
    fill(0,255,0);         
  }else if(val==9){

    ellipse(100,100,100,100);
    fill(0,255,0);  
  }
  else if(val==10){

    ellipse(100,100,100,100);
    fill(255,0,0);  
  }
  else if(val==11){

    ellipse(100,100,100,100);
    fill(255,255,0);  
  }
  else if(val==12){

    ellipse(100,100,100,100);
    fill(0,0,255);  
  }
}


/*

// Wiring / Arduino Code
// Code for sensing a switch status and writing the value to the serial port.

int switchPin = 4;                       // Switch connected to pin 4

void setup() {
  pinMode(switchPin, INPUT);             // Set pin 0 as an input
  Serial.begin(9600);                    // Start serial communication at 9600 bps
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {  // If switch is ON,
    Serial.write(1);               // send 1 to Processing
  } else {                               // If the switch is not ON,
    Serial.write(0);               // send 0 to Processing
  }
  delay(100);                            // Wait 100 milliseconds
}

*/