/* input.ino
 * Author Diego Perez (http://hotboards.org)
 * read a single pin from the IO expander
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
    pin.begin( );
    // set the pin as input (there is no need to specify the pin becuase is only one)
    pin.mode( INPUT );
    // we need the serial port for this example
    Serial.begin( 9600 );
}

void loop( void )
{
    if( pin.read( ) == 0u )
    {
        Serial.print( "pin in LOW state\n\r" );
    }
    else
    {
        Serial.print( "pin in HIGH state\n\r" );
    }
    // wait 1 second, just to not query so often
    delay( 1000 );
}
