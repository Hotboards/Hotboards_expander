/* input_output.ino
 * Author Diego Perez (http://hotboards.org)
 * control the 8 pins on the expander using two logical ports of 4 pins each one
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and 4 pins (from 0 to pin 3)
// pin 0 will be bit 0, pin 1 is bit 1 and so on
Hotboards_expander outputs( Expander_7, 0, 1, 2, 3 );
// Create a second instance with address 7 and 4 pins (from 4 to pin 7)
// pin 4 will be bit 0, pin 5 is bit 1 and so on
Hotboards_expander inputs( Expander_7, 4, 5, 6, 7 );

void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control on both ports
    outputs.begin( );
    inputs.begin( );
    // set the entire port (4 pins) as outputs
    outputs.mode( OUTPUT );
    // set the entire port (4 pins) one pin at a time as outputs
    inputs.mode( INPUT );
}

void loop( void )
{
    uint8_t val = inputs.read( );
    outputs.write( val );
    delay( 500 );
}
