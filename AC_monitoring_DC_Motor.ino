
/*
 Stabilizer DC Motor Control 

 This program drives a DC motor.
 The motor is attached to variac.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction to regulate the AC voltage.

 Created 27 July. 2018
 by Ehsan Sarhadi

    Read AC Voltage 50 to 250 Volts 
    Reads an analog input on pin 0, converts it to voltage, and prints the  
    result to the serial monitor.
    Graphical representation is available using serial plotter   (Tools > 
    Serial Plotter menu)

// the setup routine runs once when you press reset:  
 */

void setup() {

  // initialize the serial port at 9600 bits per second::
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {

// read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 250V):
  float voltageDC = sensorValue * (5.0 / 1024.0);
  float voltageAC = sensorValue * (250.0 / 1024.0);
  // print out the value you read:
  Serial.print("DC Voltage: ");
  Serial.print(voltageDC);
  Serial.println(" Volts");
  Serial.print("AC Voltage: ");
  Serial.print(voltageAC);
  Serial.println(" Volts");
  
  delay(1000);   

  // Relay #10 & Relay #12 are connected to 9-12 DC voltage
  // DC motor will rotate clockwise by turnning on the #12 Relay 
  // DC motor will rotate anticlockwise by turnning on the #10 Relay 
  
  digitalWrite(12, LOW);    // turn the Relay off by making the voltage LOW
  digitalWrite(10, LOW);    // turn the Relay off by making the voltage LOW
  
  // step one revolution  in one direction:
  if (voltageDC>4.50) digitalWrite(12, HIGH);   // turn the Relay on (HIGH is the voltage level)
  if (voltageDC>4.50) delay(1000);                       // wait for a second
  if (voltageDC>4.50) digitalWrite(12, LOW);    // turn the Relay off by making the voltage LOW
  delay(1000);                       // wait for a second

  // step one revolution in the other direction:
  if (voltageDC<4.30) digitalWrite(10, HIGH);   // turn the Relay on (HIGH is the voltage level)
  if (voltageDC<4.30) delay(1000);                       // wait for a second
  if (voltageDC<4.30) digitalWrite(10, LOW);    // turn the Relay off by making the voltage LOW
  delay(1000);                       // wait for a second
}

