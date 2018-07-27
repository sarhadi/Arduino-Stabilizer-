# Arduino-Stabilizer-

AC Measurement using Arduino for Automatic Voltage Stabilizer 

AC voltage when measured using a micro controller is a pretty difficult task as the wave gets easily distorted due to numerous noise present in the environment.Therefore for proper design of the hardware is very necessary.
The transformer is used for step down purpose because the arduino is capable of reading voltage in the range of 0-5V only. 
AC voltage measurement can be carried out by converting AC voltage into DC Voltage using rectifier.
A diode bridge is an arrangement of four (or more) diodes in a bridge circuit configuration that provides the same polarity of output for either polarity of input.

Open the Serial Monitor from (Tools>>Serial Monitor), Set Baud rate to 9600, See the AC voltage reading in serial monitor.

Now you are abale to monitor the AC voltage and keep it on 220 by moving the DC motor on variac Stabilizer.
