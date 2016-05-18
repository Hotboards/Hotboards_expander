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

class Hotboards_expander
{
    public :
        Hotboards_expander( uint8_t address, int pin0 );
        Hotboards_expander( uint8_t address, int pin0, int pin1 );
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2 );
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3 );
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4 );
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5 );
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6 );
        Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7 );
        bool begin( void );
        void write( uint8_t val );
        void write( uint8_t pin, bool val );
        void mode( bool mode );
        void mode( uint8_t pin, bool mode );

    private:
        uint8_t readReg( uint8_t reg );
        void writeReg( uint8_t reg, uint8_t val );
        uint8_t _address;
        uint8_t _pin[ 8 ];
        uint8_t _pins;
};

#endif
