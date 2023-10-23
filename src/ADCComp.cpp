/*
 * ADCComp.cpp
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#include <cstdio>
#include "ADCComp.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

ADCComp::ADCComp() {
	for (int i=0; i < ADC_TEST_MAX; i++){
		xMaxs[i] = 100.0;
		xMins[i] = 0.0;
	}
}

ADCComp::~ADCComp() {
	// NOP
}

void ADCComp::setup(){
    adc_init();

    for (int i=0; i < ADC_TEST_MAX; i++){
		if (xMaxs[i] <= 3.3){
			adc_gpio_init(i + 26);
		}
	}
}

bool ADCComp::test(){
	bool res = true;
	for (int i=0; i < ADC_TEST_MAX; i++){
		if (xMaxs[i] <= 3.3){
			adc_select_input(i);
			uint16_t r = adc_read();
			float v = (float)r * (3.3 / (float)4095);
			if ( (v > xMaxs[i]) || (v < xMins[i])){
				printf("GPIO %d %d volts %f  min %f max %f\n", i + 26, r, v, xMins[i], xMaxs[i]);
				res = false;
			}
		}
	}
	return res;
}

void ADCComp::addADC(uint gpio, float minVolt, float maxVolt){
	if ((gpio >= 26) && (gpio <= 28)){
		int a = gpio - 26;
		xMins[a] = minVolt;
		xMaxs[a] = maxVolt;
	}
}

