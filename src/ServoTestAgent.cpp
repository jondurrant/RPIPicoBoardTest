/*
 * ServoTestAgent.cpp
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#include "ServoTestAgent.h"

#define DELAY 200

ServoTestAgent::ServoTestAgent() {
	//NOP

}

ServoTestAgent::~ServoTestAgent() {
	// NOP
}

void ServoTestAgent::addServo(uint8_t gpio){
	if (xNumServos < MAX_SERVOS){
		xServos[xNumServos].setGPIO(gpio);
		xNumServos++;
	}
}

void ServoTestAgent::run(){

	for (;;){
		uint32_t sem = ulTaskNotifyTake(  pdTRUE, 3000);
		if (sem > 0){
			xCycle = true;
			for (int i=0; i < xNumServos; i++){
				xServos[i].goDegree(10.0);
				vTaskDelay(DELAY);
			}
			vTaskDelay(DELAY*2);
			for (int i=0; i < xNumServos; i++){
				xServos[i].goDegree(170.0);
				vTaskDelay(DELAY);
			}
			xCycle = false;
		}
	}

}




configSTACK_DEPTH_TYPE ServoTestAgent::getMaxStackSize(){
	return 256;

}

