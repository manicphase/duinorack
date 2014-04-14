void setup() {
}


boolean ishigh = false;

long readstep = 0;
long readlimit = 10000;
// On almost all arduino boards we pay a penalty of about 1/10000
// of a second for each analog read we make. This may not seem like
// but our code will be run several thousand times per second and
// using "analogRead" an excessive amount of times can be detrimental.
// "readstep" will count up to "readlimit" and only then take a reading
// in order to save us prescious cycles. Feel free to experiment
// with readlimit to see what difference it makes to our output.

int tonepot = map(analogRead(A0),0,1023,1,50);
// we now have to declare this integer outside the main loop as
// it wouldn't otherwise persistantly exist within the scope of the
// main loop. Notice we've reduced the amount of code written to two
// lines by putting the "analogRead" function within the "map" function.

void loop() {
  if (readstep = readlimit){
    readstep = 0;
    //Reset "readstep" to start over again climbing to "readlimit"
    tonepot = map(analogRead(A0),0,1023,1,50);
  }
  
  readstep = readstep + 1;
  // Add one to our "readstep" each cycle, until it reaches "readlimit"
  // and triggers the above section of code.
  
  
  delay(tonepot);
  
  ishigh = !ishigh;
  
  digitalWrite(9, ishigh);
}
