/* pins_output.ino
 * Author Diego Perez (http://hotboards.org)
 * control 4 pins individualy or all at once
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and 4 pins (from 4 to pin 7)
// pin 4 will be bit 0, pin 5 is bit 1 and so on
Hotboards_expander port( Expander_7, 4, 5, 6, 7 );

void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control the entire port
    port.begin( );
    // set the 4 pins that we choose to b part of the port as output
    port.mode( OUTPUT );
}

void loop( void )
{
    // lets control each pin individualy
    port.write( 0, HIGH ); // bit 0 is controled by pin 4 on the expander
    port.write( 1, LOW );  // bit 1 is controled by pin 5 on the expander
    port.write( 2, HIGH ); // bit 2 is controled by pin 6 on the expander
    port.write( 3, LOW );  // bit 3 is controled by pin 7 on the expander
    delay( 200 );

    port.write( 0, LOW );
    port.write( 1, HIGH );
    port.write( 2, LOW );
    port.write( 3, HIGH );
    delay( 500 );

    // since our port consist of 4 pins we can control this pins as an entire port
    port.write( 0x00 ); // all pins off
    delay( 200 );
    port.write( 0x0F ); // all pins on
    delay( 200 );
    port.write( 0x00 ); // all pins off
    delay( 500 );
}
