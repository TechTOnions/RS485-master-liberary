/*
   This library can be used with both Software serial & hardware serial.
   This example shows you how to Write Single Coil(FC=05) from slave device with slave ID 1 and baud 9600, Data bit 8, parity none, stop bit 1
*/

/***********************************************************************
  Written by Dharmik.
  Copyright (C) 2020
  gpl-3.0, all text above must be included in any redistribution
 ***********************************************************************/
 
#include <RS485.h>

#define RS485_slave1_port Serial2       //you can use any hardware serial port just define here

//use below function like this if not using an enable pin for RS485, else comment it
RS485 TO_RS485 (&RS485_slave1_port);  //calling defined port to ES485 lib

//if using enable pin for RS485 uncoment below code and comment above line
/*
  #define RS485_enable_pin 1      // define your digital enable pin over here
  ES485 TO_RS485 (&RS485_slave1_port,RS485_enable_pin);
*/

int16_t Write_value = 555;    // Value to be written.
unsigned int address1 = 100;  // Coil Address where we want to write new value
void setup() {
  Serial.begin(9600);
  TO_RS485.begin(9600);                 //define baud here for your RS485
  // Note: Make sure that slave device is working on same baud rate.
  //       right now library only supports data bit 8, parity none & stop bit 1

  delay(1000);

  //TO_RS485.write_single_reg(slave_ID,Write_value);

  //here 1 is slave ID
  //address1 is the coil address where we want to write.
  //write_value is value to be written

  //therefore this function will write 555 in coil no. 100 of slave ID 1.
  TO_RS485.write_single_coil(1, address1, Write_value); // it uses function code 05
  delay(1000);

}

void loop() {

}
