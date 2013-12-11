RobotSensing
=============

The robot uses 3 sets of IR sensors: left, right, and center

Functions
=========

void initSensors();

  *This initializes the sensors by enabling the ADC10 interupt and selecting SMCLK

  
Get reading from center sensor
============================
  *int CenterSensorScan(){
  *        ADC10CTL0 &= ~ENC;                                                        //Clear
  *       ADC10CTL1 = INCH_3;                       // input A3
  *       ADC10AE0 |= BIT3;                         // PA.1 ADC option select
  *        ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
  *        __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
  *    return ADC10MEM;
  *}

  * The left and right sensor have a similar code with the differences on the channels
  * First the sensor is cleared and a reading is taken which return the reading from the sensor(ADC10MEM)
  

LEDs
============================


  * In the main program, the left sensor scans. If the sensor is an inch away from an obstacle, the left LED (P1.0) lights up. Then a delay occurs so only one interrupt occurs in a certain time frame. The right sensor scans next. If the sensor is an inch away from an obstacle, the right LED (P1.6) lights up. When the sensors are away from any obstable (greater than 2 inches), the respective light is off. The right sensor is a lot weaker compared to the left sensor. This is why the threshold is 1FF for the right and 2FF for the left for the same distance.
  
Documentation: C2C Busho explained that I needed to clear my bits when I set ADC10CTL1 = to something
