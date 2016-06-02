/* ports.ino
 * Author Diego Perez (http://hotboards.org)
 * control two external expansion port using a single i2c bus
 * both has been configured with diffrent address using the Ax pads
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and 8 pins (the entire port)
Hotboards_expander port1( Expander_7, 0, 1, 2, 3, 4, 5, 6, 7 );
// Create one instance with address 6 and 8 pins (A0 has been short circuited it)
Hotboards_expander port2( Expander_6, 0, 1, 2, 3, 4, 5, 6, 7 );


void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control each port
    port1.begin( );
    port2.begin( );
    // set the entire port as inputs (8 pins)
    port1.mode( INPUT );
    // set the entire port as outputs (8 pins)
    port2.mode( OUTPUT );
}

void loop( void )
{
    // read the port number 1
    uint8_t val = port1.read( );
    // write the value on port 2
    port2.write( val );
    // a little delay, there is no need to read so often
    delay( 200 );
}
