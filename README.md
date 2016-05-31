Hotboards_expander
===============

Genial libreria de proposito general para controlar el magnifico expansor de puertos Microchip MCP23008, puedes manejar hasta 8 pines los cuales pueden ser configurados como entradas y/o salidas, a demas la libreria te permite controlar mas de un expansor conectado al mismo bus I2C. Descarga la libreria en formato [**zip**](https://github.com/Hotboards/Hotboards_expander/archive/master.zip), renombre el archivo ( _solo quita el **-master**_ ) e importala a tu Arduino IDE com dice [**aqui**](https://www.arduino.cc/en/Guide/Libraries).

API
---

**Hotboards_expander( uint8_t address, int pin0, int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7 )**

Constructor para incializar pines del expansor de puertos. Puedes manipular de 1 solo pin hasta los ocho pines del puerto completo, el primer parametro es la direccion de bus i2c que tendra el expansor (configurable de 0 a 7).

``` cpp
/* creamos un solo pin el pin 5 del expansor */
Hotboards_expander pín( Expander_7, 5 );
/* creamos un puerto con los pines del expansor 0, 1, 2 y 3.
   En el pin 0 esta el pin0, y en el pin 3 esta el pin3 */
Hotboards_expander port( Expander_7, 0, 1, 2 ,3 );
/* creamos un puerto con todos los pines del expansor */
Hotboards_expander port( Expander_7, 0, 1, 2 ,3, 4, 5, 6, 7 );
```

**void mode( bool mode )**

Configura a todos los pines del puerto creado como salidas o como entradas. Los valores aceptados son INPUT y OUTPUT

``` cpp
/* creamos un solo pin el pin 5 del expansor */
Hotboards_expander pín( Expander_7, 5 );
pin.mode( OUTPUT );

/* creamos un puerto con los pines del expansor 0, 1, 2 y 3.
   En el pin 0 esta el pin0, y en el pin 3 esta el pin3 */
Hotboards_expander port( Expander_7, 0, 1, 2 ,3 );
/* los 4 pines configurados como entradas */
port.mode( INPUT );
```

**void mode( uint8_t pin, bool mode )**

Configura uno solo de los pines del puerto creado como salida o como entrada. Los valores aceptados son INPUT y OUTPUT

``` cpp
/* creamos un puerto con los pines del expansor 0, 1, 2 y 3.
   En el pin 0 esta el pin0, y en el pin 3 esta el pin3 */
Hotboards_expander port( Expander_7, 0, 1, 2 ,3 );
/* pin 0 configurado como salida */
port.mode( 0, OUTPUT );
/* pin 2 configurado como entrada */
port.mode( 2, INPUT );
```

**void write( uint8_t val )**

Escribe un valor en el puerto completo, los pines necesitan estar configurados como salidas

``` cpp
/* creamos un puerto con los pines del expansor 0, 1, 2 y 3.
   En el pin 0 esta el pin0, y en el pin 3 esta el pin3 */
Hotboards_expander port( Expander_7, 0, 1, 2 ,3 );
/* los 4 pines configurados como salidas */
port.mode( OUTPUT );
/* escribimos un 10 (como son 4 bits solo aceptara valores del 0 al 15)
port.write( 10 );

/* creamos un puerto con todos los pines del expansor */
Hotboards_expander port( Expander_7, 0, 1, 2 ,3, 4, 5, 6, 7 );
/* los 8 pines configurados como salidas */
port.mode( OUTPUT );
/* escribe el valor 134 (son 8 bits asi que aceptara valores de 0 a 255)
port.write( 134 );
```

**void write( uint8_t pin, bool val )**

Escribe un valor boleano (0 o 1) es uno de los pines del puerto, el pin debe estar configurado como salida

``` cpp
/* creamos un puerto con los pines del expansor 0, 1, 2 y 3.
   En el pin 0 esta el pin0, y en el pin 3 esta el pin3 */
Hotboards_expander port( Expander_7, 0, 1, 2 ,3 );
/* los 4 pines configurados como salidas */
port.mode( OUTPUT );
/* escribimos un '1' en el pin2 y un '0' en el pin3 */
port.write( 2, 1 );
port.write( 3, 0 );
```

**uint8_t read( uint8_t pin=0xff )**

Lee el estado de los pines en el puerto creado. Puede ser el valor de un solo pin o de todo el puerto.

``` cpp
/* creamos un pin en pin 7 y leemos su estado (0 o 1) */
Hotboards_expander pin( 7 );
bool val = pin.read( );

/* creamos un puerto de 8 pines (pin 0->pin0 ..... pin 7->pin7) */
Hotboards_expander port( 0, 1, 2, 3, 4, 5, 6, 7 );
/* leemos el valor del puerto (valores de 0 a 255) */
uint8_t val = port.read( );

/* creamos un puerto de 4 pins (pin 0->pin0 ..... pin 3->pin3) */
Hotboards_expander port( 0, 1, 2, 3 );
/* leemos el estado del pin 1 */
bool val1 = port.write( 1 );
/* leemos el estado del pin 0 */
bool val2 = port.write( 0 );
```
