// include the SevenSegmentTM1637 library
#include "SevenSegmentTM1637.h"
#include "SevenSegmentExtended.h"

/* initialize global TM1637 Display object
*  The constructor takes two arguments, the number of the clock pin and the digital output pin:
* SevenSegmentTM1637(byte pinCLK, byte pinDIO);
*/
const byte PIN_CLK = 4;   // define CLK pin (any digital pin)
const byte PIN_DIO = 5;   // define DIO pin (any digital pin)
SevenSegmentExtended      display(PIN_CLK, PIN_DIO);
int digitalPin1 = 11;
int digitalPin2 = 12;
int position1;
int position2;
int count = 0;

// run setup code
void setup() {
  Serial.begin(9600);         // initializes the Serial connection @ 9600 baud
  display.begin();            // initializes the display
  display.setBacklight(100);  // set the brightness to 100 %
  display.print("INIT");  
  pinMode(digitalPin1, INPUT);
  pinMode(digitalPin2, INPUT);
  Serial.begin(9600);
};

// run loop (forever)
void loop() {
 position1 = digitalRead(digitalPin1); 
 position2 = digitalRead(digitalPin2); 
  
  if ( position1 == 0) {  
     count++;
     Serial.println(count);
     display.print(count);
      
 } else if (position2 == 0) {

      count--;
      Serial.println(count);
      display.print(count);
 }
    delay(500);    
};

