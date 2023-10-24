/*
 * PicoOnboardLED.h
 *
 * Test flash the onboard LED for a Pico (not Pico-W).
 * Will just flash once per test
 *
 *  Created on: 22 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_PICOONBOARDLED_H_
#define SRC_PICOONBOARDLED_H_

#include "BoardTest.h"
#include "pico/stdlib.h"

#define DELAY 500 // in microseconds

class PicoOnboardLED : public BoardTest {
public:
	PicoOnboardLED();
	virtual ~PicoOnboardLED();

	virtual void setup();
	virtual bool test();

private:
	 uint LED_PIN = PICO_DEFAULT_LED_PIN;
};

#endif /* SRC_PICOONBOARDLED_H_ */
