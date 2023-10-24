/*
 * LEDsTest.h
 *
 * Flash LEDS a number of times according to value in sequence.
 * 1st LED is flashed once. 2nd LED is flashed twice, etc.
 *  Created on: 22 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_LEDSTEST_H_
#define SRC_LEDSTEST_H_

#include "BoardTest.h"
#include "pico/stdlib.h"

#define DELAY 500 // in microseconds

#define LEDS_TEST_MAX 10

class LEDsTest : public BoardTest {
public:
	LEDsTest();
	virtual ~LEDsTest();

	/***
	 * Setup the tests
	 */
	virtual void setup();

	/***
	 * Run test
	 * @return true of passed
	 */
	virtual bool test();

	/***
	 * Add an LED
	 * @param sequence - sequence
	 * @param gpio - GPIO PAd
	 * @param invert - invert if it is in sync pattern
	 */
	void addLed(uint sequence, uint gpio, bool invert = false);

private:

	uint xGPIOs[LEDS_TEST_MAX];
	bool xInverts[LEDS_TEST_MAX];
	uint xMaxLED = 0;

};

#endif /* SRC_LEDSTEST_H_ */
