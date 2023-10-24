/*
 * BoardTests.cpp
 *
 *  Created on: 24 Oct 2023
 *      Author: jondurrant
 */

#include "BoardTests.h"

BoardTests::BoardTests() {
	// TODO Auto-generated constructor stub

}

BoardTests::~BoardTests() {
	// TODO Auto-generated destructor stub
}

void BoardTests::addTest(TestAgentInterface *test){
	xTests.push_back(test);
}

void BoardTests::runCycle(){
	for (TestAgentInterface * test: xTests ){
		  test->startCycle();
	}
	vTaskDelay(500);

	bool cycleComplete = false;

	while (!cycleComplete){
	  int completeCount = 0;
	  for (TestAgentInterface * test: xTests ){
		  if (!test->isCycleComplete()){
			 break;
		  } else {
			  completeCount++;
		  }
	  }
	  if (xTests.size() == completeCount){
		  cycleComplete = true;
	  }
	  vTaskDelay(500);
	}
}

int BoardTests::passRate(){
	int passCount = 0;
	for (TestAgentInterface * test: xTests ){
	  if (test->isTestOK()){
		  passCount++;
	  }
	}
	return passCount;
}

int BoardTests::testCount(){
	return xTests.size();
}

void BoardTests::printFailures(){
	for (TestAgentInterface * test: xTests ){
		  if (!test->isTestOK()){
			  printf("Test failed %s\n", test->getName());
		  }
	}
}

void BoardTests::run(){
	for (;;){
		 printf("Start test cycle\n");
		 runCycle();
		 int pass = passRate();
		 int total = testCount();
		 if (pass != total){
			 printFailures();
		 }
		 printf("Tests passed %d of %d\n", pass, total);
	}
}
