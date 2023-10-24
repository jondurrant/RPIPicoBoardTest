/*
 * BoardTests.h
 *
 *  Created on: 24 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_BOARDTESTS_H_
#define SRC_BOARDTESTS_H_

#include "FreeRTOS.h"
#include "task.h"

#include <cstdio>
#include <list>

#include "TestAgentInterface.h"

class BoardTests {
public:
	BoardTests();
	virtual ~BoardTests();

	void addTest(TestAgentInterface *test);

	void runCycle();
	int passRate();
	int testCount();

	void printFailures();

	void run();

private:

	  std::list<TestAgentInterface *> xTests;

};

#endif /* SRC_BOARDTESTS_H_ */
