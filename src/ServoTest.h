/*
 * ServoTest.h
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
	ServoTest(uint gpio);
	virtual ~ServoTest();

	virtual void setup();
    virtual bool test();

	void setGPIO(uint gpio);

private:
	Servo xServo;
};

#endif /* SRC_SERVOTEST_H_ */
