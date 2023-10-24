/*
 * ADCComp.h
 *
 * Board Test for ADC. Test up to 3 ADC on Pico
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_ADCCOMP_H_
#define SRC_ADCCOMP_H_

#include "BoardTest.h"
#include "pico/stdlib.h"

#define ADC_TEST_MAX 3

class ADCComp: public BoardTest {
public:
	ADCComp();
	virtual ~ADCComp();

	/***
	 * Setup the GPIO s ADC
	 */
	virtual void setup();

	/***
	 * Do a ADC cycle and check in range
	 * @return
	 */
	virtual bool test();

	/***
	 * Add GPIO to test ADC for
	 * @param gpio - must be ADC pin 26 to 28
	 * @param minVolt - minimum volts
	 * @param maxVolt - maximum volts
	 */
	void addADC(uint gpio, float minVolt, float maxVolt);

private:

	float xMins[ADC_TEST_MAX];
	float xMaxs[ADC_TEST_MAX];

};

#endif /* SRC_ADCCOMP_H_ */
