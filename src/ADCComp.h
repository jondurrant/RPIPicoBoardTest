/*
 * ADCComp.h
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

	virtual void setup();
	virtual bool test();

	void addADC(uint gpio, float minVolt, float maxVolt);

private:

	float xMins[ADC_TEST_MAX];
	float xMaxs[ADC_TEST_MAX];

};

#endif /* SRC_ADCCOMP_H_ */
