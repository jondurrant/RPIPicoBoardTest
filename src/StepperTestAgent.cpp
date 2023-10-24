/*
 * StepperTestAgent.cpp
 *
 *  Created on: 24 Oct 2023
 *      Author: jondurrant
 */

#include "StepperTestAgent.h"

StepperTestAgent::StepperTestAgent(uint8_t gp1, uint8_t gp2, uint8_t gp3, uint8_t gp4 ):
    Stepper28BYJ(gp1, gp2, gp3, gp4){

}

StepperTestAgent::~StepperTestAgent() {
	// NOP
}

void StepperTestAgent::startCycle(){
	stepStop();
	stepContinuous(12, xClockwise);
	xClockwise = ! xClockwise;
}

bool StepperTestAgent::isCycleComplete( ){
	return true;
}

bool StepperTestAgent::isTestOK(){
	return true;
}

const char * StepperTestAgent::getName(){
	return pcTaskGetName(getTask());
}
