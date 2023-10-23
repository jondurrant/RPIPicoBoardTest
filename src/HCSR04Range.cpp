/*
 * HCSR04Range.cpp
 *
 *  Created on: 5 Sept 2023
 *      Author: jondurrant
 */

#include "HCSR04Range.h"
#include "hardware/gpio.h"
#include "GPIOInputMgr.h"
#include <cstdio>


HCSR04Range::HCSR04Range(){
	xGPTrigger = 0xFF;
	xGPEcho = 0xFF;
}

HCSR04Range::HCSR04Range(uint8_t GPTrigger, uint8_t GPEcho){
	setGP(GPTrigger, GPEcho);
}


void HCSR04Range::setGP(uint8_t GPTrigger, uint8_t GPEcho){

	xGPTrigger = GPTrigger;
	xGPEcho = GPEcho;

	gpio_init(GPTrigger);
	gpio_set_dir(GPTrigger, GPIO_OUT);

	GPIOInputMgr::getMgr()->addObserver(xGPEcho,  this);

}

HCSR04Range::~HCSR04Range() {
	// TODO Auto-generated destructor stub
}


void HCSR04Range::trigger(){
	if (xGPTrigger > 28){
		return;
	}
	gpio_put (xGPTrigger,true);
	sleep_us(10);
	gpio_put (xGPTrigger,false);

}

int HCSR04Range::getDistanceMM(){
	if (xEchoEnd <= xEchoStart){
		return -1;
	}
	uint64_t us = xEchoEnd - xEchoStart;

	float mm = (0.340 * (float)us) / 2.0;
	return (int)mm;
}

/***
 * handle GPIO  events
 * @param gpio - GPIO number
 * @param events - Event
 */
 void HCSR04Range::handleGPIO(uint gpio, uint32_t events){
	 uint64_t now = to_us_since_boot (get_absolute_time());
	 if (gpio == xGPEcho){
		 if ((events & GPIO_IRQ_EDGE_RISE)  > 0) {
			 xEchoStart = now;
		 }
		 if ((events &  GPIO_IRQ_EDGE_FALL) > 0){
			 xEchoEnd = now;
		 }
	 }
 }
