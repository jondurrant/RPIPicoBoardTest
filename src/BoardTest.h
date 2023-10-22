/*
 * BoardTest.h
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

	virtual void setup();
	virtual void tearDown();

	virtual bool test()=0;
};

#endif /* SRC_BOARDTEST_H_ */
