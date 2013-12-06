// TI example code

#include <msp430g2553.h>
#include "RobotSensing.h"

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  initSensors();

  P1DIR |= 0x41;                            // Set P1.0 to output direction

  for (;;)
  {
	  LeftSensorScan();

    if (ADC10MEM > 0x2FF)
    	P1OUT |= BIT0;
    	else
        	P1OUT &= ~BIT0;

    _delay_cycles(200000);
    RightSensorScan();

    if (ADC10MEM > 0x200)
        P1OUT |= BIT6;                      // Set P1.0 LED on
    	else
    		P1OUT &= ~BIT6;    					// Clear P1.0 and P1.6 LED off
    _delay_cycles(200000);
  }
    return 0;
}


