/* port_input.ino
 * Author Diego Perez (http://hotboards.org)
 * control the entire port, yes 8 pins as inputs
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
    // set the entire port as inputs (8 pins)
    port.mode( INPUT );
    // we need the serial port on this example
    Serial.begin( 9600 );
}

void loop( void )
{
    // read the entire port
    uint8_t val = port.read( );
    // send to serial the value read it
    Serial.print( "port = " );
    Serial.println( val, BIN );
    // a little delay, there is no need to read so often
    delay( 200 );
}
