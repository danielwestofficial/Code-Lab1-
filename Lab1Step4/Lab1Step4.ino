/*This scenario considers a desk lamp with adjustable brightness controlled by a button
when the button is pressed and released, it toggles the state of the LED (on or off). 
When the button is held down, it gradually increases the brightness of the LED using PWM.
To make the LED dim again the button needs to be continually held down.*/

const int LED = 9;                                  //constant integer for LED connected to pin 9
const int BUTTON = 2;                                 //variable containing the button connected to pin 2

boolean lastButton = LOW;                           //variable containing the previous button state
boolean currentButton = LOW;                        //variable containing the current button state
boolean ledOn = false;                              //the present state of the LED (on/off)
int brightness = 0;                                 //initial brightness level

void setup() {
  pinMode(LED, OUTPUT);                             //pin 9 is an output for the LED
  pinMode(BUTTON, INPUT);                           //pin 2 is an input for the button
}

/* BUTTON DEBOUNCING FUNCTION */
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);            //read the button state
  if (last != current) {                            //if it’s different
    delay(5);                                       //wait 5ms
    current = digitalRead(BUTTON);                  //read it again
  }
  return current;                                   //return the current value
}

void loop() {
  currentButton = debounce(lastButton);             //read debounced state
  
  if (lastButton == LOW && currentButton == HIGH) { //if the button was pressed
    ledOn = !ledOn;                                 //toggle the LED value
  }

  lastButton = currentButton;                       //reset button value
  
  if (ledOn) {
    analogWrite(LED, brightness);                   //set the LED brightness
  } else {                                          //otherwise
    analogWrite(LED, 0);                            //turn off the LED
  }

  // Adjust brightness when the button is held down
  if (currentButton == HIGH) {                      //if current button is HIGH
    brightness = (brightness + 5) % 255;           //increase brightness in increments of 5
                                                    //then uses the modulus operator % ensures the range of 255
    delay(100);                                     //delay for smooth adjustment
  }
}
