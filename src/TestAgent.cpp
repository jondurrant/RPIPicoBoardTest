/*
 * TestAgent.cpp
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#include "TestAgent.h"

TestAgent::TestAgent() {
	// NOP

}

TestAgent::~TestAgent() {
	// NOP
}

void TestAgent::startCycle(){
	xTaskNotifyGive(xHandle);
}

bool TestAgent::isCycleComplete(){
	return xCycle;
}

bool TestAgent::isTestOK(){
	return true;
}
