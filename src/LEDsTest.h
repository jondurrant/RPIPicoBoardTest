/*
 * LEDsTest.h
 *
 *  Created on: 22 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_LEDSTEST_H_
#define SRC_LEDSTEST_H_

#include "BoardTest.h"
#include "pico/stdlib.h"

#define DELAY 500 // in microseconds

#define LEDS_TEST_MAX 10

class LEDsTest {
public:
	LEDsTest();
	virtual ~LEDsTest();

	virtual void setup();
	virtual bool test();

	void addLed(uint sequence, uint gpio, bool invert = false);

private:

	uint xGPIOs[LEDS_TEST_MAX];
	bool xInverts[LEDS_TEST_MAX];
	uint xMaxLED = 0;

};

#endif /* SRC_LEDSTEST_H_ */
