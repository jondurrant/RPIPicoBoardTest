/*
 * LEDsTest.cpp
 *
 *  Created on: 22 Oct 2023
 *      Author: jondurrant
 */

#include "LEDsTest.h"

LEDsTest::LEDsTest() {
	for (int i=0; i < LEDS_TEST_MAX; i++){
		xGPIOs[i] = 0xFF;
		xInverts[i] = false;
	}

}

LEDsTest::~LEDsTest() {
	// TODO Auto-generated destructor stub
}


void LEDsTest::setup(){
	for (int i=0; i < LEDS_TEST_MAX; i++){
		if (xGPIOs[i] <= 28 ){
			gpio_init(xGPIOs[i]);
			gpio_set_dir(xGPIOs[i], GPIO_OUT);
			gpio_put(xGPIOs[i],  xInverts[i]);
			xMaxLED = i;
		}
	}
}

bool LEDsTest::test(){
	for (int flashCount=0; flashCount <= xMaxLED; flashCount++){
		//On
		for (int i=flashCount; i <= xMaxLED; i++){
			if (xGPIOs[i] <= 28){
				gpio_put(xGPIOs[i], !xInverts[i]);
			}
		}
		vTaskDelay(DELAY);

		//Off
		for (int i=flashCount; i <= xMaxLED; i++){
			if (xGPIOs[i] <= 28){
				gpio_put(xGPIOs[i], xInverts[i]);
			}
		}
		vTaskDelay(DELAY);
	}

	return true;
}

void LEDsTest::addLed(uint sequence, uint gpio, bool invert){
	if ( (sequence > 0) && (sequence < LEDS_TEST_MAX)){
		xGPIOs[sequence-1] = gpio;
		xInverts[sequence-1] = invert;
	}
}


