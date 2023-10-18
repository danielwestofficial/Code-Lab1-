const int LED = 9;                            // constant integer for LED connected to pin 9
void setup() {
  pinMode(LED, OUTPUT);                       // pin 9 is an output
}
void loop() {
  for (int i = 255 ; i >= 0; i--) {           // fade out from max to min in increments of 1
  analogWrite(LED, i);                      // sets the value (range from 255 to 0)
  delay(10);                                // wait for 10 milliseconds to see the dimming effect
  }
  for (int i = 0 ; i <= 255; i++) {           // fade in from min to max in increments of 1 points:
  analogWrite(LED, i);                      // sets the value (range from 0 to 255)
  delay(10);                                // wait for 10 milliseconds to see the dimming effect
  }
}
