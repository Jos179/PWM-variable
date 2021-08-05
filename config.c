#include <xc.h>

void ConfigOscilador( void )
{
    // Configura el Oscilador interno a 500Khz
    OSCCONbits.IRCF = 0b000;//a 31KHz 1/08/21
}

void ConfigPuerto( void )
{   
    ADCON1bits.PCFG=0xFF; //todos los pines del puerto A como entradas o saiidas digitales
    //UCONbits.USBEN=0;
    //UCFGbits.UTRDIS=1;
    TRISD = 0x00;//pines del puerto D como salida
    TRISB = 0x00;//pines del puerto B como salida
    TRISA = 0b00000011;//los 2 primeros pines del puerto A como entrada, los demas salida 
    LATA = 0x00;
    LATD = 0b00000000;
    LATB = 0b11111111;
}

void delay_ms( unsigned long t )
{
    unsigned long i;
    t*=250;
    for(i=0;i<t;i++)
        ;
}
