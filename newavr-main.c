/*
 * File:   newavr-main.c
 * Author: Lenovo
 *
 * Created on March 19, 2024, 7:34 PM
 */


#include <avr/io.h>
#include <util/delay.h>



int main(void) {
 PORTB_DIRSET = PIN4_bm;
 PORTB.DIRCLR = PIN2_bm;   
 PORTB.PIN2CTRL = PORT_PULLUPEN_bm;
    PORTA_DIRSET = PIN7_bm;
    CLKCTRL_MCLKCTRLA |= CLKCTRL_CLKOUT_bm | CLKCTRL_CLKSEL_OSCHF_gc; 
//    CLKCTRL_MCLKCTRLB &= ~CLKCTRL_PEN_bm ; 
    CLKCTRL_MCLKCTRLC |= CLKCTRL_CFDSRC_CLKMAIN_gc | CLKCTRL_CFDEN_bm;
    CLKCTRL_OSCHFCTRLA |= CLKCTRL_RUNSTDBY_bm | CLKCTRL_FRQSEL_1M_gc;
    
    
  while(1){ 
while( !(PORTB.IN & PIN2_bm) ){
    PORTB.OUTSET = PIN4_bm;
    _delay_ms(2000);
    PORTB.OUTCLR = PIN4_bm;
    _delay_ms(2000);
}
}
} 


