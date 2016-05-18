/* output.ino
 * Author Diego Perez (http://hotboards.org)
 * control 4 pins individualy or all at once
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and 4 pins (from 4 to pin 7)
// pin 4 will be bit 0, pin 5 is bit 1 and so on
Hotboards_expander port1( Expander_7, 0, 1, 2, 3 );
Hotboards_expander port2( Expander_7, 4, 5, 6, 7 );

void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control the entire port
    port2.begin( );
    port1.begin( );
    // set the 4 pins that we choose to b part of the port as output
    port2.mode( OUTPUT );
    port1.mode( 0, OUTPUT );
    port1.mode( 1, OUTPUT );
    port1.mode( 2, OUTPUT );
    port1.mode( 3, OUTPUT );
}

void loop( void )
{
    // lets control each pin individualy
    port2.write( 0x0f ); // bit 0 is controled by pin 4 on the expander
    port1.write( 0x00 );  // bit 1 is controled by pin 5 on the expander
    delay( 500 );

    port2.write( 0x00 ); // bit 0 is controled by pin 4 on the expander
    port1.write( 0x0f );  // bit 1 is controled by pin 5 on the expander
    delay( 500 );
}
