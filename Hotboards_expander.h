/*
  Hotboards_expander.h - Driver to read and control a serial (i2c) port expander, The Microchip
  MCP23008 is the digital sensor to control, can be read it, set its resolution, shutdown and also
  set alarms.
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
 *  Used to control general purpose leds
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
          * @param pin0 physical pin used as pin 0
          *
          * Example:
          * @code
          *   // instance one pin on pin 5
          *   Hotboards_expander pin( 5 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0 );

        /** Create Hotboards_expander instance for two pins
          * @param address expansion port i2c physical address
          * @param pin0 physical pin used as pin 0
          * @param pin1 physical pin used as pin 1
          *
          * Example:
          * @code
          *   // instance two pins on pin 2 and 3
          *   Hotboards_expander port( 2, 3 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1 );

        /** Create Hotboards_expander instance for three pins
          * @param address expansion port i2c physical address
          * @param pin0 physical pin used as pin 0
          * @param pin1 physical pin used as pin 1
          * @param pin2 physical pin used as pin 2
          *
          * Example:
          * @code
          *   // instance three pins on pin 1, 2 and 3
          *   Hotboards_expander port( 1, 2, 3 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2 );

        /** Create Hotboards_expander instance for four pins
          * @param address expansion port i2c physical address
          * @param pin0 physical pin used as pin 0
          * @param pin1 physical pin used as pin 1
          * @param pin2 physical pin used as pin 2
          * @param pin3 physical pin used as pin 3
          *
          * Example:
          * @code
          *   // instance four pins on pin 0, 1, 2 and 3
          *   Hotboards_expander port( 0, 1, 2, 3 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3 );

        /** Create Hotboards_expander instance for five pins
          * @param address expansion port i2c physical address
          * @param pin0 physical pin used as pin 0
          * @param pin1 physical pin used as pin 1
          * @param pin2 physical pin used as pin 2
          * @param pin3 physical pin used as pin 3
          * @param pin4 physical pin used as pin 4
          *
          * Example:
          * @code
          *   // instance five pins on pin 0, 1, 2, 3 and 4
          *   Hotboards_expander port( 0, 1, 2, 3, 4 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4 );

        /** Create Hotboards_expander instance for six pins
          * @param address expansion port i2c physical address
          * @param pin0 physical pin used as pin 0
          * @param pin1 physical pin used as pin 1
          * @param pin2 physical pin used as pin 2
          * @param pin3 physical pin used as pin 3
          * @param pin4 physical pin used as pin 4
          * @param pin5 physical pin used as pin 5
          *
          * Example:
          * @code
          *   // instance six pins on pin 0, 1, 2, 3, 4 and 5
          *   Hotboards_expander port( 0, 1, 2, 3, 4, 5 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5 );

        /** Create Hotboards_expander instance for seven pins
          * @param address expansion port i2c physical address
          * @param pin0 physical pin used as pin 0
          * @param pin1 physical pin used as pin 1
          * @param pin2 physical pin used as pin 2
          * @param pin3 physical pin used as pin 3
          * @param pin4 physical pin used as pin 4
          * @param pin5 physical pin used as pin 5
          * @param pin6 physical pin used as pin 6
          *
          * Example:
          * @code
          *   // instance seven pins on pin 0, 1, 2, 3, 4, 5 and 6
          *   Hotboards_expander port( 0, 1, 2, 3, 4, 5, 6 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6 );

        /** Create Hotboards_expander instance for eight pins
          * @param address expansion port i2c physical address
          * @param pin0 physical pin used as pin 0
          * @param pin1 physical pin used as pin 1
          * @param pin2 physical pin used as pin 2
          * @param pin3 physical pin used as pin 3
          * @param pin4 physical pin used as pin 4
          * @param pin5 physical pin used as pin 5
          * @param pin6 physical pin used as pin 6
          * @param pin7 physical pin used as pin 7
          *
          * Example:
          * @code
          *   // instance eight pins on pin 0, 1, 2, 3, 4, 5, 6 and 7
          *   Hotboards_expander port( 0, 1, 2, 3, 4, 5, 6, 7 );
          * @endcode
          */
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7 );
        bool begin( void );
  
        /**
          */
        void mode( bool mode );
        
        /**
          */
        void mode( uint8_t pin, bool mode );

        /** Write a value on the entire instance port
          * @param val value to be written
          *
          * Example:
          * @code
          *   // instance one pin on pin 7 and write a 1 (aceptara valores de 0 a 1)
          *   Hotboards_expander pin( 7 );
          *   pin.mode( OUTPUT );
          *   pin.write( 1 );
          *
          *   // instance a 4 pins bus (pin2->led3 ..... pin5->led0)
          *   Hotboards_expander port( 2, 3, 4, 5 );
          *   port.mode( OUTPUT );
          *   // write the 10 value (it will accept values from 0 to 15)
          *   port.write( 10 );
          *
          *   // instance an 8 leds bus (pin4->led7 ..... pin3->led0)
          *   Hotboards_leds leds( 4, 3, 2, 6, 5, 7, 8, 9 );
          *   // write the 134 value (it will accept values from 0 to 255)
          *   leds.write( 134 );
          * @endcode
          */
        void write( uint8_t val );
        void write( uint8_t pin, bool val );
        uint8_t read( uint8_t pin=0xff );

    private:
        uint8_t readReg( uint8_t reg );
        void writeReg( uint8_t reg, uint8_t val );
        uint8_t _address;
        uint8_t _pin[ 8 ];
        uint8_t _pins;
};

#endif
