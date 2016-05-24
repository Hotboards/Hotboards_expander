/* port_output.ino
 * Author Diego Perez (http://hotboards.org)
 * control the entire port, yes 8 pins as outputs
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and 8 pins (the entire port)
Hotboards_expander port( Expander_7, 0, 1, 2, 3, 4, 5, 6, 7 );

void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control the entire port
    port.begin( );
    // set the entire port as output
    port.mode( OUTPUT );
}

void loop( void )
{
    for( uint8_t i=0 ; i<256 ; i++ )
    {
        // display the 'i' value on the leds
        port.write( i );
        delay( 200 );
    }
}
