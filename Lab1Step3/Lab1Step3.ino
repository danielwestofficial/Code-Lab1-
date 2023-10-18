const int LED = 9;                              //constant integer for LED connected to pin 9
const int BUTTON = 2;                             //variable containing the BUTTON connected to pin 2
boolean lastButton = LOW;                       //variable containing the previous button state
boolean currentButton = LOW;                    //variable containing the current button state
boolean ledOn = false;                          //the present state of the LED (on/off)

void setup() {
  pinMode(LED, OUTPUT);                         // pin 9 is an output
  pinMode(BUTTON, INPUT);                       // pin 2 is an input
}
/*BUTTON DEBOUNCING FUNCTION*/
boolean debounce(boolean last)
{
boolean current = digitalRead(BUTTON);          //read the button state
if (last != current)                            // if it’s different
{
delay(5);                                       //wait 5ms
current = digitalRead(BUTTON);                  //read it again
}
return current;                                 //return the current value
}

void loop(){
currentButton = debounce(lastButton);           //read debounced state
if (lastButton == LOW && currentButton == HIGH) //if it was pressed
{
ledOn = !ledOn;                                 //toggle the LED value
}
lastButton = currentButton;                     //reset button value
digitalWrite(LED, ledOn);                       //change the LED state
}
