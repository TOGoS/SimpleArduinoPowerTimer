#include <Arduino.h>

#define POWER_PIN D1
#define POWERED_TIME_MS (1000*60*60*6)

/* Wiring:
 *
 * The system has a 0V,12V input and a 0V,12V output
 * (0Vin, 12Vin, 0Vout, 12Vout, respectively).
 * A momentary button and a MOSFET in parallel switch the 0V,
 * (because it's easier to switch using a MOSFET than the 12V),
 * so 0Vin -> switch/mosfet -> 0Vout
 * A 12V->5V voltage regulator is attached to 0Vout,12Vout to make 5Vout.
 * The arduino/ESP/whatever is powered by 0Vout,5Vout.
 *
 * Behavior:
 *  
 * When first powered, the program applies 5V to the gate of the mosfet so that it stays connected
 * afdter the button is no longer pressed.
 * After a delay (POWERED_TIME_MS milliseconds) the gate is unpowered (set to 0V)
 * and then the whole system will cease to be powered and shut off.
 */

void setup() {
  pinMode(POWER_PIN, OUTPUT);
  digitalWrite(POWER_PIN, HIGH);
  delay(POWERED_TIME_MS);
  digitalWrite(POWER_PIN, LOW);
}

void loop() {
}
