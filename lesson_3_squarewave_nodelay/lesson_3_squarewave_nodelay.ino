void setup() {
}


boolean ishigh = false;

long readstep = 0;
long readlimit = 10000;
long tonepotaccumulator = 0;
long tonepotacculimit = 10000;
// as with "readstep" and "readlimit", we will use "tonepotaccumulator" and
// "tonepotacculimit" to increase a number until it's reached a limit which 
// we will use to trigger an event.


int tonepot = analogRead(A0);
// The scales of the numbers we are working with this time are not restricted
// in the same way as the last few lessons, so we've removed the map function 
// to make things simpler.

void loop() {
  if (readstep = readlimit){
    readstep = 0;
    tonepot = analogRead(A0);
  }
  readstep = readstep + 1;
  
  tonepotaccumulator = tonepotaccumulator + tonepot;
  if (tonepotaccumulator >= tonepotacculimit){
    ishigh = !ishigh;
    // When the accumulator reaches the limit; switch the state of "ishigh" 
    tonepotaccumulator = tonepotaccumulator - tonepotacculimit;
    // and start counting up again. "tonepotaccumulator" can be set to 0
    // ant it will increase tone in steps instead of smoothly.
  }
  // This time around. We have completely removed the "delay()" function.
  // Now the loop will run at a constant rate. We are manipulating the tone
  // by checking whether it's reached a limit before switching the output pin on
  // or off.
  // This has many awesome advantages such as being able to use different
  // waveforms, multiple waves, effects and LFOs.
  
  digitalWrite(9, ishigh);
}
