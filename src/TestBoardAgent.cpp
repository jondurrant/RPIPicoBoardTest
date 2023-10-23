/*
 * TestBoardAgent.cpp
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#include "TestBoardAgent.h"

TestBoardAgent::TestBoardAgent() {
	// NOP
}

TestBoardAgent::~TestBoardAgent() {
	// NOP
}

TestBoardAgent::TestBoardAgent(BoardTest *p) {
	setBoardTest(p);
}

void TestBoardAgent::setBoardTest(BoardTest *p){
	pTest = p;
}

bool TestBoardAgent::isTestOK(){
	return xResult;
}



/***
 * Task main run loop
 */
void TestBoardAgent::run(){

	for (;;){
			uint32_t sem = ulTaskNotifyTake(  pdTRUE, 3000);
			if (sem > 0){
				xCycle = true;
				if (pTest != NULL){
					pTest->setup();
					xResult = pTest->test();
					pTest->tearDown();
				}
				xCycle = false;
			}
		}
}

/***
 * Get the static depth required in words
 * @return - words
 */
configSTACK_DEPTH_TYPE TestBoardAgent::getMaxStackSize(){
	return 256;
}
