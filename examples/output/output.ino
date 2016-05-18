/* output.ino
 * Author Diego Perez (http://hotboards.org)
 * control and blink a single led on pin0
 */

#include <Arduino.h>
#include <Wire.h>
#include <Hotboards_expander.h>

// Create one instance with address 7 and just one pin to control
// in this case is the first pin of the expander module
Hotboards_expander pin( Expander_7, 0 );

void setup( void )
{
    // this module needs the I2C so we need to init the wire library
    Wire.begin( );
    // reset the internal registers that control the pin selected
    port.begin( );
    // set the pin as output (there is no need to specify the pin becuase is only one)
    pin.mode( OUTPUT );
}

void loop( void )
{
    // set to high
    pin.write( HIGH );
    delay( 200 );
    // set to low
    pin.write( LOW );
    delay( 200 );
}
