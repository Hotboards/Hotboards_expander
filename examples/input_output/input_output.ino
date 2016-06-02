/* input_output.ino
 * Author Diego Perez (http://hotboards.org)
 * configure 4 pins as outputs and 4 pins as inputs
 * 
 * led0 ----\
 * led1     |  leds
 * led2     |
 * led3 ----/
 * led4 ----\
 * led5     |  dipsw
 * led6     |
 * led7 ----/
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and 4 pins (from 0 to pin 3)
// pin 0 will be bit 0, pin 1 is bit 1 and so on
Hotboards_expander outputs( Expander_7, 0, 1, 2, 3 );
// Create a second instance with address 7 (same expansion port) and 4 pins (from 4 to pin 7)
// pin 4 will be bit 0, pin 5 is bit 1 and so on
Hotboards_expander inputs( Expander_7, 4, 5, 6, 7 );

void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control both ports
    outputs.begin( );
    inputs.begin( );
    // set the entire port (4 pins) as outputs
    outputs.mode( OUTPUT );
    // set the entire port (4 pins) as inputs
    inputs.mode( INPUT );
}

void loop( void )
{
    // read the inputs
    uint8_t val = inputs.read( );
    // write the value read it
    outputs.write( val );
    // delay
    delay( 500 );
}
