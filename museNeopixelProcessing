import oscP5.*;
import netP5.*;

OscP5 oscP5;
NetAddress myRemoteLocation;

import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  println(Serial.list());
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 115200);
  oscP5 = new OscP5(this,12000);
}

void draw() {
  background(255);
  rect(50, 50, 100, 100);         // Draw a square
}

void mousePressed() {
  if (mouseOverRect() == true) {  // If mouse is over square,
    fill(204);                    // change color and
    myPort.write("setColor r\n");              // send an H to indicate mouse is over square
    println("0");
  } 
  else {                        // If mouse is not over square,
    fill(0);                      // change color and
    myPort.write("setColor g\n");              // send an L otherwise
    println("1");
  }
}
boolean mouseOverRect() { // Test if mouse is over square
  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150));
}

void oscEvent(OscMessage theOscMessage) {
  /* check if theOscMessage has the address pattern we are looking for. */
  
  if(theOscMessage.checkAddrPattern("/muse/elements/alpha_relative")==true) {
    /* check if the typetag is the right one. */
    //if(theOscMessage.checkTypetag("f")) {
      /* parse theOscMessage and extract the values from the osc message arguments. */
      float firstValue = theOscMessage.get(0).floatValue();  
      float firstValue1 = theOscMessage.get(1).floatValue();  
      float firstValue2 = theOscMessage.get(2).floatValue();  
      float firstValue3 = theOscMessage.get(3).floatValue();  
      print("### received an osc message /test with typetag" + theOscMessage.typetag());
      println(" values: "+firstValue+" "+firstValue1+" "+firstValue2+" "+firstValue3);
      if(firstValue2 > 0.3) {
        myPort.write("setColor g\n");
      } else if(firstValue2 > 0.18) {
        myPort.write("setColor b\n");
      } else {
        myPort.write("setColor r\n");
      }
    //}  
  } 
  //println("### received an osc message. with address pattern "+theOscMessage.addrPattern());
}
