/*
  Hotboards_expander.h - Driver to read and control a serial (i2c) port expansion chip, The Microchip
  MCP23008 can manipulate up to 8 digital I/O with interrupt detection and pullups configuration.
  Hotboards eeprom board (http://hotboards.org)
  Created by Diego Perez, March 19, 2016.
  Released into the public domain.
*/

#ifndef Hotboards_expander_h
#define Hotboards_expander_h

#include <Arduino.h>

typedef enum
{
    Expander_0 = 0,
    Expander_1,
    Expander_2,
    Expander_3,
    Expander_4,
    Expander_5,
    Expander_6,
    Expander_7
} _eExpander;

/** Hotboards_expander class.
 *  Used to control Microchip MCP23008 expansion port
 *
 * Example:
 * @code
 * #include "Hotboards_expander.h"
 *
 * Hotboards_expander pin( Expander_7, 0 );
 *
 * void setup( void )
 * {
 *     pin.mode( OUTPUT );
 * }
 *
 * void loop( void )
 * {
 *     pin.write( HIGH );
 *     delay( 200 );
 *     pin.write( LOW );
 *     delay( 200 );
 * }
 * @endcode
 */
class Hotboards_expander
{
    public :
        /** Create Hotboards_expander instance for one pin
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          *
          * Example:
          * @code
          *   // instance one pin on physical pin  5
          *   Hotboards_expander pin( 5 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0 );

        /** Create Hotboards_expander instance for two pins
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          * @param pin1 physical expander pin used as pin 1
          *
          * Example:
          * @code
          *   // instance two pins on physical pins 2 and 3
          *   Hotboards_expander port( 2, 3 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1 );

        /** Create Hotboards_expander instance for three pins
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          * @param pin1 physical expander pin used as pin 1
          * @param pin2 physical expander pin used as pin 2
          *
          * Example:
          * @code
          *   // instance three pins on physical pins 1, 2 and 3
          *   Hotboards_expander port( 1, 2, 3 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2 );

        /** Create Hotboards_expander instance for four pins
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          * @param pin1 physical expander pin used as pin 1
          * @param pin2 physical expander pin used as pin 2
          * @param pin3 physical expander pin used as pin 3
          *
          * Example:
          * @code
          *   // instance four pins on physical pins 0, 1, 2 and 3
          *   Hotboards_expander port( 0, 1, 2, 3 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3 );

        /** Create Hotboards_expander instance for five pins
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          * @param pin1 physical expander pin used as pin 1
          * @param pin2 physical expander pin used as pin 2
          * @param pin3 physical expander pin used as pin 3
          * @param pin4 physical expander pin used as pin 4
          *
          * Example:
          * @code
          *   // instance five pins on physical pins 0, 1, 2, 3 and 4
          *   Hotboards_expander port( 0, 1, 2, 3, 4 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4 );

        /** Create Hotboards_expander instance for six pins
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          * @param pin1 physical expander pin used as pin 1
          * @param pin2 physical expander pin used as pin 2
          * @param pin3 physical expander pin used as pin 3
          * @param pin4 physical expander pin used as pin 4
          * @param pin5 physical expander pin used as pin 5
          *
          * Example:
          * @code
          *   // instance six pins on physical pins 0, 1, 2, 3, 4 and 5
          *   Hotboards_expander port( 0, 1, 2, 3, 4, 5 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5 );

        /** Create Hotboards_expander instance for seven pins
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          * @param pin1 physical expander pin used as pin 1
          * @param pin2 physical expander pin used as pin 2
          * @param pin3 physical expander pin used as pin 3
          * @param pin4 physical expander pin used as pin 4
          * @param pin5 physical expander pin used as pin 5
          * @param pin6 physical expander pin used as pin 6
          *
          * Example:
          * @code
          *   // instance seven pins on physical pins 0, 1, 2, 3, 4, 5 and 6
          *   Hotboards_expander port( 0, 1, 2, 3, 4, 5, 6 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6 );

        /** Create Hotboards_expander instance for eight pins
          * @param address expansion port i2c physical address
          * @param pin0 physical expander pin used as pin 0
          * @param pin1 physical expander pin used as pin 1
          * @param pin2 physical expander pin used as pin 2
          * @param pin3 physical expander pin used as pin 3
          * @param pin4 physical expander pin used as pin 4
          * @param pin5 physical expander pin used as pin 5
          * @param pin6 physical expander pin used as pin 6
          * @param pin7 physical expander pin used as pin 7
          *
          * Example:
          * @code
          *   // instance eight pins on physical pins 0, 1, 2, 3, 4, 5, 6 and 7
          *   Hotboards_expander port( 0, 1, 2, 3, 4, 5, 6, 7 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7 );
        bool begin( void );

        /** Change the port mode
          * @param mode port mode INPUT, OUTPUT and PULLUP
          *
          * Example:
          * @code
          *   // instance one pin on pin 7 and write a 1 (only boolean values 0 or 1)
          *   Hotboards_expander pin( 7 );
          *   pin.mode( OUTPUT );
          *
          *   // instance a 4 pins port (pin 0->pin0 ..... pin 3->pin3)
          *   Hotboards_expander port( 0, 1, 2, 3 );
          *   // the four pins as configured as outputs
          *   port.mode( INPUT );
          * @endcode
          */
        void mode( bool mode );

        /** Change the pin mode
          * @param mode pin mode INPUT, OUTPUT and PULLUP
          *
          * Example:
          * @code
          *   // instance one pin on pin 7 and set the pin as OUTPUT
          *   Hotboards_expander pin( 7 );
          *   pin.mode( 0, OUTPUT );
          *
          *   // instance a 4 pins port (pin 0->pin0 ..... pin 3->pin3)
          *   Hotboards_expander port( 0, 1, 2, 3 );
          *   // the pin0 (expander pin 0) as output
          *   port.mode( 0, OUTPUT );
          *   // the pin2 (expander pin 2) as input
          *   port.mode( 2, INPUT );
          * @endcode
          */
        void mode( uint8_t pin, bool mode );

        /** Write a value on the entire instance port
          * @param val value to be written (0 or 1)
          *
          * Example:
          * @code
          *   // instance one pin on pin 7 and write a 1 (only boolean values 0 or 1)
          *   Hotboards_expander pin( 7 );
          *   pin.mode( OUTPUT );
          *   pin.write( 1 );
          *
          *   // instance a 4 pins port (pin 0->pin0 ..... pin 3->pin3)
          *   Hotboards_expander port( 0, 1, 2, 3 );
          *   // the four pins as configured as outputs
          *   port.mode( OUTPUT );
          *   // write the 10 value (it will accept values from 0 to 15)
          *   port.write( 10 );
          *
          *   // instance an 8 pins port (pin 0->pin0 ..... pin 7->pin7)
          *   Hotboards_expander port( 0, 1, 2, 3, 4, 5, 6, 7 );
          *   // write the 134 value (it will accept values from 0 to 255)
          *   port.write( 134 );
          * @endcode
          */
        void write( uint8_t val );

        /** Write a boolean value on single pin
          * @param pin the port pin to be written
          * @param val value to be written
          *
          * Example:
          * @code
          *   // instance one pin on pin 7 and write a 1 (only boolean values 0 or 1)
          *   Hotboards_expander pin( 7 );
          *   pin.mode( OUTPUT );
          *   pin.write( 0, 1 ); // the first pin is always indetified as 0
          *
          *   // instance a 4 pins port (pin 0->pin0 ..... pin 3->pin3)
          *   Hotboards_expander port( 0, 1, 2, 3 );
          *   // the four pins are configured as outputs
          *   port.mode( OUTPUT );
          *   // write a '1' on pin2 (pin 2) and a '0' on pin3 (pin 3)
          *   port.write( 2, 1 );
          *   port.write( 3, 0 );
          * @endcode
          */
        void write( uint8_t pin, bool val );

        /** Read a single pin or the entire defined port
          * @param pin the port pin to be read
          * @return value read it
          *
          * Example:
          * @code
          *   // instance one pin on pin 7 and read its state (0 o 1)
          *   Hotboards_expander pin( 7 );
          *   bool val = pin.read( );
          *
          *   // instance an 8 pins port (pin 0->pin0 ..... pin 7->pin7)
          *   Hotboards_switches port( 0, 1, 2, 3, 4, 5, 6, 7 );
          *   // read the port value (from 0 to 255)
          *   uint8_t val = port.read( );
          *
          *   // instance a 4 pin port (pin 0->pin0 ..... pin 3->pin3)
          *   Hotboards_switches port( 0, 1, 2, 3 );
          *   // read pin 1
          *   bool val1 = port.read( 1 );
          *   // read pin 0
          *   bool val2 = port.read( 0 );
          *   //read the entire port (4 pins)
          *   uint8_t val = port.read( );
          * @endcode
          */
        uint8_t read( uint8_t pin=0xff );

    private:
        uint8_t readReg( uint8_t reg );
        void writeReg( uint8_t reg, uint8_t val );
        uint8_t _address;
        uint8_t _pin[ 8 ];
        uint8_t _pins;
};

#endif
