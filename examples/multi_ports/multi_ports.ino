/* multi_ports.ino
 * Author Diego Perez (http://hotboards.org)
 * control the 8 pins on the expander using two logical ports of 4 pins each one
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and 4 pins (from 0 to pin 3)
// pin 0 will be bit 0, pin 1 is bit 1 and so on
Hotboards_expander port1( Expander_7, 0, 1, 2, 3 );
// Create a second instance with address 7 and 4 pins (from 4 to pin 7)
// pin 4 will be bit 0, pin 5 is bit 1 and so on
Hotboards_expander port2( Expander_7, 4, 5, 6, 7 );

void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control on both ports
    port2.begin( );
    port1.begin( );
    // set the entire port (4 pins) as outputs
    port2.mode( OUTPUT );
    // set the entire port (4 pins) one pin at a time as outputs
    port1.mode( 0, OUTPUT );
    port1.mode( 1, OUTPUT );
    port1.mode( 2, OUTPUT );
    port1.mode( 3, OUTPUT );
}

void loop( void )
{
    port2.write( 0x0f );  // set to HIGH pins 4,5,6 and 7
    port1.write( 0x00 );  // set to LOW pins 0,1,2 and 3 
    delay( 500 );

    port2.write( 0x00 );  // set to LOW pins 4,5,6 and 7
    port1.write( 0x0f );  // set to HIGH pins 0,1,2 and 3 
    delay( 500 );
}
