void setup() {
}


boolean ishigh = false;
// A boolean is a single bit switch which can either be on or off.
// (Different parts of our code may use different words which all
// do the same thing;- 1, HIGH and "true" are the same. 0, LOW and 
// "false" are the same.)
// We will use this bit to switch between apllying a voltage or not
// to our audio output. Rapidly switching between HIGH and LOW
// will create a square wave at our audio output

void loop() {
  int tonepot = analogRead(A0);
  // "tonepot" is short for tone potentiometer. This is the 
  // potentiometer we use to adjust the tone. It is wire to analog
  // imput 0 or "A0" as the arduino library understands it.
  
  tonepot = map(tonepot,0,1023,1,50);
  // This line is not strictly neccesary. All we are doing is 
  // the number given by tone pot in order to cut off inaudible
  // outputs and limit this to what should output between 500hz
  // (1ms HIGH and 1ms LOW) and 10hz (50ms HIGH and 50ms LOW).
  // There are a few problems with this which we will address later.
  
  delay(tonepot);
  // this is where we tell the arduino to wait the chosen time before
  // switching the state of our output pin.
  
  ishigh = !ishigh;
  // This is quick cheeky way of switching a boolean variable.
  // As a boolean only has two states telling one to NOT be it's own
  // state using ! forces it to be it's only other possible state
  // ie, HIGH is NOT LOW - LOW = !HIGH.
  
  digitalWrite(9, ishigh);
  // And finally this is where we tell the arduino to set the output
  // voltage on our output pin. LOW = 0V, HIGH = 5V (3.3V on the DUE)
}
