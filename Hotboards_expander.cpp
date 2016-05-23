
#include "Hotboards_expander.h"
#include <Wire.h>

#define REG_ODIR            (uint8_t)0x00 // I/O direction
#define REG_IPOL            (uint8_t)0x01 // Input polarity
#define REG_GPINTEN         (uint8_t)0x02 // Interrupt enable
#define REG_DEFVAL          (uint8_t)0x03 //
#define REG_INTCON          (uint8_t)0x04
#define REG_IOCON           (uint8_t)0x05 // configuration register
#define REG_GPPU            (uint8_t)0x06 // Pull ups
#define REG_INTF            (uint8_t)0x07 // int flags
#define REG_INTCAP          (uint8_t)0x08 //
#define REG_GPIO            (uint8_t)0x09 // read register
#define REG_OLAT            (uint8_t)0x0A // write register

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0 )
{
    _address = address | 0x20;
    _pins = 1;
    _pin[ 0 ] = pin0;
}

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0, int pin1 )
{
    _address = address | 0x20;
    _pins = 2;
    _pin[ 0 ] = pin0;
    _pin[ 1 ] = pin1;
}

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2 )
{
    _address = address | 0x20;
    _pins = 3;
    _pin[ 0 ] = pin0;
    _pin[ 1 ] = pin1;
    _pin[ 2 ] = pin2;
}

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3 )
{
    _address = address | 0x20;
    _pins = 4;
    _pin[ 0 ] = pin0;
    _pin[ 1 ] = pin1;
    _pin[ 2 ] = pin2;
    _pin[ 3 ] = pin3;
}

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4 )
{
    _address = address | 0x20;
    _pins = 5;
    _pin[ 0 ] = pin0;
    _pin[ 1 ] = pin1;
    _pin[ 2 ] = pin2;
    _pin[ 3 ] = pin3;
    _pin[ 4 ] = pin4;
}

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5 )
{
    _address = address | 0x20;
    _pins = 6;
    _pin[ 0 ] = pin0;
    _pin[ 1 ] = pin1;
    _pin[ 2 ] = pin2;
    _pin[ 3 ] = pin3;
    _pin[ 4 ] = pin4;
    _pin[ 5 ] = pin5;
}

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6 )
{
    _address = address | 0x20;
    _pins = 7;
    _pin[ 0 ] = pin0;
    _pin[ 1 ] = pin1;
    _pin[ 2 ] = pin2;
    _pin[ 3 ] = pin3;
    _pin[ 4 ] = pin4;
    _pin[ 5 ] = pin5;
    _pin[ 6 ] = pin6;
}

Hotboards_expander::Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7 )
{
    _address = address | 0x20;
    _pins = 8;
    _pin[ 0 ] = pin0;
    _pin[ 1 ] = pin1;
    _pin[ 2 ] = pin2;
    _pin[ 3 ] = pin3;
    _pin[ 4 ] = pin4;
    _pin[ 5 ] = pin5;
    _pin[ 6 ] = pin6;
    _pin[ 7 ] = pin7;
}

bool Hotboards_expander::begin( void )
{
    uint8_t i, j;
    uint8_t reg = readReg( REG_ODIR );

    for( i=0 ; i<_pins ; i++ )
    {
        bitWrite( reg, _pin[ i ], 1 );
    }
    writeReg( REG_ODIR, reg );

    for( j=1 ; j<11 ; j++ )
    {
        reg = readReg( j );
        for( i=0 ; i<_pins ; i++ )
        {
            bitWrite( reg, _pin[ i ], 0 );
        }
        writeReg( j, reg );
    }
}

void Hotboards_expander::write( uint8_t val )
{
    uint8_t i;
    uint8_t olat = readReg( REG_OLAT );

    for( i=0 ; i<_pins ; i++ )
    {
        bitWrite( olat, _pin[ i ], bitRead( val, i ) );
    }

    writeReg( REG_OLAT, olat );
}

void Hotboards_expander::write( uint8_t pin, bool val )
{
    uint8_t olat = readReg( REG_OLAT );

    bitWrite( olat, _pin[ pin ], val );

    writeReg( REG_OLAT, olat );
}

uint8_t Hotboards_expander::read( uint8_t pin )
{
    uint8_t i;
    uint8_t val = 0;
    uint8_t gpio = readReg( REG_GPIO );

    if( pin == 0xff )
    {
        for( i=0 ; i<_pins ; i++ )
        {
            bitWrite( val, i, bitRead( gpio, i ) );
        }
    }
    else
    {
        val = bitRead( gpio, pin );
    }
    return val;
}

void Hotboards_expander::mode( bool mode )
{
    uint8_t i;
    uint8_t odir = readReg( REG_ODIR );

    for( i=0 ; i<_pins ; i++ )
    {
        bitWrite( odir, _pin[ i ], !mode );
    }

    writeReg( REG_ODIR, odir );
}

void Hotboards_expander::mode( uint8_t pin, bool mode )
{
    uint8_t odir = readReg( REG_ODIR );

    bitWrite( odir, _pin[ pin ], !mode );

    writeReg( REG_ODIR, odir );
}


uint8_t Hotboards_expander::readReg( uint8_t reg )
{
    Wire.beginTransmission( _address );
    Wire.write( reg );
    Wire.endTransmission( );

    Wire.requestFrom( _address, (uint8_t)1 );
    return Wire.read( );
}

void Hotboards_expander::writeReg( uint8_t reg, uint8_t val )
{
    Wire.beginTransmission( _address );
    Wire.write( reg );
    Wire.write( val );
    Wire.endTransmission( );
}
