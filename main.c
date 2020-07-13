/*
 * Nombre del archivo:   main.c
 *
 * Descripción: 
 *        Este programa es un ejemplo para practicar trabajo colaborativo
 *        usando git como herramienta de control de versiones.
 * 
 * Autores:
 *        Nahuel Espinosa
 *        Francisco Janza
 *        Agustín Oliva
 *        Lucas Vaccaro
 *        Francisco Janza
 *        Matias Oliva
 *        Guido Navia
 */

#include <xc.h>
#include <stdint.h>

/* ------------------------ Definiciones ------------------------------------ */
#define _XTAL_FREQ  4000000L    // Frecuencia de operación del cristal

/* ------------------------ Bits de configuración --------------------------- */
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
//#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

/* ------------------------ Prototipos de funciones ------------------------- */
void gpioConfig();

// Funciones de UART
void uartConfig();
void uartWrite(uint8_t dato);
void uartWriteString(uint8_t string[]);

// TODO: Agregar prototipo de función que imprime tu nombre y apellido
void printNahuelEspinosa();

/* ------------------------ Implementación de funciones --------------------- */
void main(void) {               // Función principal
    gpioConfig();               // Inicializo las entradas y salidas
    uartConfig();               // Inicializo el puerto serie
    
    // TODO: Agregar el llamado a la función que imprime tu nombre y apellido
    printNahuelEspinosa();
    
    while(1) {                  // Super loop
        __delay_ms(10);
    }
    
    return;
}

// Función que configura los pines como entradas o salidas según la necesidad
void gpioConfig() {
    ANSEL = 0;                  // Configuro todas las entradas como digitales
    ANSELH = 0; 
}

// Función que configura la UART
void uartConfig() {
    TX9 = 0;                    // Transmisión de 8 bits
    TXEN = 1;                   // Habilito la transmisión
    SYNC = 0;                   // Modo asincrónico
    
    BRGH = 1;                   // Valor de tabla (9600 bps)
    SPBRG = 25;                 // Valor de tabla (9600 bps)
    RX9 = 0;                    // Recepció de 8 bits
    
    CREN = 1;                   // Habilito la recepción continua
    SPEN = 1;                   // Habilito el puerto serie
}

// Función que transmite un byte por puerto serie
void uartWrite(uint8_t dato) {
    while(TXIF == 0);           // Espero que el transmisor esté libre
    TXREG = dato;               // Transmito el byte
}

// Función que recibe una cadena de caracteres y los transmite uno por uno
void uartWriteString(uint8_t string[]) {
    uint8_t i;
    
    for( i = 0 ; string[i] != 0 ; i++ ) {   // Repito hasta que termine el string
        uartWrite( string[i] );             // Transmito el caracter en la posición i
    }
}

// TODO: Agregar implementación de función que imprime tu nombre y apellido
void printNahuelEspinosa() {
    uartWriteString("NahuelEspinosa\r\n");
}
/* ------------------------ Fin de archivo ---------------------------------- */
 *        José Morales
 *        Lucas Vaccaro
 *        Francisco Janza
 *        Candela Silva Diniz
 *        Matias Oliva
 *        Agustín Oliva
 *        Sebastián Pérez
 */

#include <xc.h>
#include <stdint.h>

/* ------------------------ Definiciones ------------------------------------ */
#define _XTAL_FREQ  4000000L    // Frecuencia de operación del cristal

/* ------------------------ Bits de configuración --------------------------- */
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
//#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

/* ------------------------ Prototipos de funciones ------------------------- */
void gpioConfig();

// Funciones de UART
void uartConfig();
void uartWrite(uint8_t dato);
void uartWriteString(uint8_t string[]);

// TODO: Agregar prototipo de función que imprime tu nombre y apellido
void printNahuelEspinosa();

/* ------------------------ Implementación de funciones --------------------- */
void main(void) {               // Función principal
    gpioConfig();               // Inicializo las entradas y salidas
    uartConfig();               // Inicializo el puerto serie
    
    // TODO: Agregar el llamado a la función que imprime tu nombre y apellido
    printNahuelEspinosa();
    
    while(1) {                  // Super loop
        __delay_ms(10);
    }
    
    return;
}

// Función que configura los pines como entradas o salidas según la necesidad
void gpioConfig() {
    ANSEL = 0;                  // Configuro todas las entradas como digitales
    ANSELH = 0; 
}

// Función que configura la UART
void uartConfig() {
    TX9 = 0;                    // Transmisión de 8 bits
    TXEN = 1;                   // Habilito la transmisión
    SYNC = 0;                   // Modo asincrónico
    
    BRGH = 1;                   // Valor de tabla (9600 bps)
    SPBRG = 25;                 // Valor de tabla (9600 bps)
    RX9 = 0;                    // Recepció de 8 bits
    
    CREN = 1;                   // Habilito la recepción continua
    SPEN = 1;                   // Habilito el puerto serie
}

// Función que transmite un byte por puerto serie
void uartWrite(uint8_t dato) {
    while(TXIF == 0);           // Espero que el transmisor esté libre
    TXREG = dato;               // Transmito el byte
}

// Función que recibe una cadena de caracteres y los transmite uno por uno
void uartWriteString(uint8_t string[]) {
    uint8_t i;
    
    for( i = 0 ; string[i] != 0 ; i++ ) {   // Repito hasta que termine el string
        uartWrite( string[i] );             // Transmito el caracter en la posición i
    }
}

// TODO: Agregar implementación de función que imprime tu nombre y apellido
void printNahuelEspinosa() {
    uartWriteString("NahuelEspinosa\r\n");
}
