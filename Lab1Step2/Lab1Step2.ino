const int LED = 9;                            // constant integer for LED connected to pin 9
boolean BUTTON = 2;                         // constant integer for BUTOON connected to pin 2
void setup() {
  pinMode(LED, OUTPUT);                       // pin 9 is an output
  pinMode(BUTTON, INPUT);                     // pin 2 is an input
}
void loop() {
if (digitalRead(BUTTON) == LOW) {             //if the button is low
digitalWrite(LED, LOW);                       //LED will be low
} else {                                      //otherwise
digitalWrite(LED, HIGH);                      //LED will be high
}
}
