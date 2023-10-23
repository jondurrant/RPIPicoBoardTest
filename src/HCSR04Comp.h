/*
 * HCSR04Comp.h
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
	HCSR04Comp(uint trigger, uint echo, int min, int max);
	virtual ~HCSR04Comp();

	virtual void setup();
	virtual bool test();

	void setGPIO(uint trigger, uint echo);
	void setRange(int min, int max);

private:
	int xMin = 0;
	int xMax = 0;
	HCSR04Range xHCSR04;
};

#endif /* SRC_HCSR04COMP_H_ */
