/*
 * PicoOnboardLED.cpp
 *
 *  Created on: 22 Oct 2023
 *      Author: jondurrant
 */

#include "PicoOnboardLED.h"

PicoOnboardLED::PicoOnboardLED() {
	// TODO Auto-generated constructor stub

}

PicoOnboardLED::~PicoOnboardLED() {
	// TODO Auto-generated destructor stub
}


void PicoOnboardLED::setup(){
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	gpio_put(LED_PIN, 0);
}

bool PicoOnboardLED::test(){
	gpio_put(LED_PIN, 1);
	vTaskDelay(DELAY);
	gpio_put(LED_PIN, 0);
	vTaskDelay(DELAY);
	return true;
}

