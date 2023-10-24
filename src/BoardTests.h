/*
 * BoardTests.h
 *
 * Collection of test and run as a set in parallel
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

	/***
	 * Add a test
	 * @param test
	 */
	void addTest(TestAgentInterface *test);

	/***
	 * Run a single cycle of tests
	 */
	void runCycle();

	/***
	 * Get the pass rate
	 * @return number of tests passing
	 */
	int passRate();

	/***
	 * Total number of tests
	 * @return count
	 */
	int testCount();

	/***
	 * print to stdio the test failing
	 */
	void printFailures();

	/***
	 * Continuously run the test cycles.
	 * Once one cycle completes (all tests confirm complete) cycle is restarted
	 */
	void run();

private:

	  std::list<TestAgentInterface *> xTests;

};

#endif /* SRC_BOARDTESTS_H_ */
