#include <xc.h>
#include "config.h"
#include "system.h"

//CCPRxL:CCPxCON<5:4>=PWM(duty cycle)/Tosc*16)
//0000 1011 10 (46) ->1.5ms
//0000 0111 11 (31) ->1ms
//0000 1111 10 (62) ->2ms

void main(void) {
    ConfigOscilador();
    //diferentes valores de prueba de PR2
    PR2 = 0x9A;//periodo de 0.32s (Fosc=31KHz,Prescx16)
    PR2 = 0x9A;//periodo de 0.02s (Fosc=31KHz,Prescx1)
    
    //diferentes valores de prueba de CCPR1L (orden descendente)
    //CCPR1L = 0b01001101;//para ciclo de trabajo 0.16s (Fosc=31KHz,Prescx16)
    //CCPR1L = 0b00001111;//para ciclo de trabajo 0.002s (Fosc=31KHz,Prescx1)
    //CCPR1L = 0b00000111;//para ciclo de trabajo 0.001s (Fosc=31KHz,Prescx1)
    CCPR1L = 0b00010010;//para ciclo de trabajo entre 1ms y 2ms (Fosc=31KHz,Prescx1)
    
    TRISCbits.RC1 = 0; //Salida para CCP2
    TRISCbits.RC2 = 0;//salida para CCP1
    
    T2CON = 0x00;   // Prescaler 16 Timer 2 OFF
    TMR2 = 0;
    T2CONbits.TMR2ON = 1; //Timer 2 ON
    
    //diferentes vaores de prueba para de CCP1CON (orden descendente)
    //CCP1CON = 0x2C;//para ciclo de trabajo 0.16s (Fosc=31KHz,Prescx16)
    //CCP1CON = 0x2C;//para ciclo de trabajo 0.002s (Fosc=31KHz,Prescx1)
    //CCP1CON = 0x3C;//para ciclo de trabajo 0.001s (Fosc=31KHz,Prescx1)
    CCP1CON = 0x0C;//para ciclo de trabajo entre 1ms y 2ms (Fosc=31KHz,Prescx1)
    while(1){
    }
    return;
}
