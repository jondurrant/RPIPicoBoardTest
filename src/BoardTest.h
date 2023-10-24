/*
 * BoardTest.h
 *
 * Abstract superclass for a simple (non Task) test
 *
 *  Created on: 22 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_BOARDTEST_H_
#define SRC_BOARDTEST_H_

#include "FreeRTOS.h"
#include "task.h"

class BoardTest {
public:
	BoardTest();
	virtual ~BoardTest();

	/***
	 * Setup the test. Called at start of each cycle
	 * Default is NOP
	 */
	virtual void setup();

	/****
	 * Tear down tests. Called at end of each cycle
	 */
	virtual void tearDown();

	/***
	 * Undertake test
	 * @return true of test passes
	 */
	virtual bool test()=0;
};

#endif /* SRC_BOARDTEST_H_ */
