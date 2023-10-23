/*
 * HCSR04Comp.cpp
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#include "HCSR04Comp.h"
#include <cstdio>

#define DELAY 50

HCSR04Comp::HCSR04Comp() {
	// NOP

}

HCSR04Comp::~HCSR04Comp() {
	// NOP
}

HCSR04Comp::HCSR04Comp(uint trigger, uint echo, int min, int max){
	setGPIO(trigger, echo);
	setRange(min, max);
}


void HCSR04Comp::setup(){
	//NOP
}

bool HCSR04Comp::HCSR04Comp::test(){
	xHCSR04.trigger();
	vTaskDelay(DELAY);
	int range = xHCSR04.getDistanceMM();
	if ( (range < xMin) || (range > xMax)){
		printf("Range failed %d not in range %d to %d\n", range, xMin, xMax);
		return false;
	}
	return true;
}

void HCSR04Comp::setGPIO(uint trigger, uint echo){
	xHCSR04.setGP(trigger, echo);
}

void HCSR04Comp::setRange(int min, int max){
	xMin = min;
	xMax = max;
}
