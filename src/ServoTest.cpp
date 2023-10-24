/*
 * ServoTest.cpp
 *
 *Test a servo by turning to 10deg and 170deg
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#include "ServoTest.h"

#define DELAY 3000

ServoTest::ServoTest() {
	//NOP

}

ServoTest::~ServoTest() {
	// TODO Auto-generated destructor stub
}

ServoTest::ServoTest(uint gpio){
	setGPIO(gpio);
}


void ServoTest::setup(){
	//NOP
}

bool ServoTest::test(){
	xServo.goDegree(10.0);
	vTaskDelay(DELAY);
	xServo.goDegree(170.0);
	vTaskDelay(DELAY);
	return true;
}

void ServoTest::setGPIO(uint gpio){
	xServo.setGPIO(gpio);
}
