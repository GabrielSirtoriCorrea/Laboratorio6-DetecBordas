#include <avr/io.h>
#include "bits.h"

#define DISP7SEG_UNI_ON     SETBIT(PORTB,0)
#define DISP7SEG_UNI_OFF    CLRBIT(PORTB,0)
#define DISP7SEG_DEZ_ON     SETBIT(PORTB,1)
#define DISP7SEG_DEZ_OFF    CLRBIT(PORTB,1)

#define DIGITOS7SEG_SIZE    16

unsigned char disp7seg_scan = 0;

char digitos7seg[DIGITOS7SEG_SIZE] = {  0x3F, 0x06, 0x5B, 0x4F, 
                                        0x66, 0x6D, 0x7D, 0x07, 
                                        0x7F, 0x6F, 0x77, 0x7C, 
                                        0x39, 0x5E, 0x79, 0x71  };

void display7seg_init(){
    DDRD = 0xFF;
    PORTD = 0X00;
    SETBIT(DDRB, 0);
    SETBIT(DDRB, 1);
}

void disp7seg(unsigned char d){
    if(disp7seg_scan==0){
        DISP7SEG_DEZ_OFF;
        PORTD = digitos7seg[d%10];
        DISP7SEG_UNI_ON;
    } else if(disp7seg_scan==1){
        DISP7SEG_UNI_OFF;
        PORTD = digitos7seg[(d/10)%10];
        DISP7SEG_DEZ_ON;
    }
    disp7seg_scan = ++disp7seg_scan % 2;
}

