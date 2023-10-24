/*
 * ServoTest.h
 *
 * Test a servo by turning to 10deg and 170deg
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_SERVOTEST_H_
#define SRC_SERVOTEST_H_

#include "BoardTest.h"
#include "pico/stdlib.h"
#include "Servo.h"

class ServoTest {
public:
	ServoTest();

	/***
	 * GPIO pad driving the LED
	 * @param gpio - pad
	 */
	ServoTest(uint gpio);
	virtual ~ServoTest();

	/***
	 * Setup the GPIO Pad
	 */
	virtual void setup();

	/***
	 * Run the test
	 * @return true if passed
	 */
    virtual bool test();

    /***
     * Set the GPIO PAD for the Servo
     * @param gpio
     */
	void setGPIO(uint gpio);

private:
	Servo xServo;
};

#endif /* SRC_SERVOTEST_H_ */
