/*
 * HCSR04Comp.h
 *
 * Test range is within range
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_HCSR04COMP_H_
#define SRC_HCSR04COMP_H_

#include "BoardTest.h"
#include "pico/stdlib.h"
#include "HCSR04Range.h"

class HCSR04Comp : public BoardTest{
public:
	HCSR04Comp();

	/***
	 * Set device and target range
	 * @param trigger - GPIO pin
	 * @param echo - GPIO pin
	 * @param min - min reported in mm
	 * @param max - reported in mm
	 */
	HCSR04Comp(uint trigger, uint echo, int min, int max);
	virtual ~HCSR04Comp();

	/***
	 * Setup the test
	 */
	virtual void setup();

	/***
	 * Run the test
	 * @return true if range is within min and max
	 */
	virtual bool test();

	/***
	 * Set the GPIO pads for the drivce
	 * @param trigger - GPIO  pad
	 * @param echo - GPIO pad
	 */
	void setGPIO(uint trigger, uint echo);

	/***
	 * Set range to check value against
	 * @param min - mm
	 * @param max - mm
	 */
	void setRange(int min, int max);

private:
	int xMin = 0;
	int xMax = 0;
	HCSR04Range xHCSR04;
};

#endif /* SRC_HCSR04COMP_H_ */
