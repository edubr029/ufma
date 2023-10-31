#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic16f84a.h>

// Configuration word
__CONFIG(FOSC_XT & WDTE_OFF & PWRTE_OFF & CP_OFF);

void configIO(){
    TRISAbits.TRISA1 = 1; // configura RA1 como entrada
    TRISAbits.TRISA2 = 1; // configura RA2 como entrada
    TRISAbits.TRISA3 = 1; // configura RA3 como entrada
    TRISAbits.TRISA4 = 1; // configura RA4 como entrada

    TRISBbits.TRISB0 = 0; // configura RB0 como saída
    TRISBbits.TRISB1 = 0; // configura RB1 como saída
    TRISBbits.TRISB2 = 0; // configura RB2 como saída
}


void systemControl(){
    short int I = PORTAbits.RA1; // configura RA1 como I
    short int A = PORTAbits.RA2; // configura RA2 como A
    short int B = PORTAbits.RA3; // configura RA3 como B
    short int C = PORTAbits.RA4; // configura RA4 como C

    while(I){
        short int Eve = (!A && !B) || (!A && C);    // 'A.'B + 'A.C
        short int Evs = (B && C);                 // B.C
        short int Err = (B && !C) || (A && !B);     // B.'C + A.'B

        PORTBbits.RB0 = Evs; // configura RB0 como Evs
        PORTBbits.RB1 = Eve; // configura RB1 como Eve
        PORTBbits.RB2 = Err; // configura RB2 como Err
    }
}

void main(){
    configIO();
    systemControl();

    return;
}