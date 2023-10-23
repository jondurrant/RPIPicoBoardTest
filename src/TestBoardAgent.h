/*
 * TestBoardAgent.h
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_TESTBOARDAGENT_H_
#define SRC_TESTBOARDAGENT_H_

#include "TestAgent.h"

#include "BoardTest.h"

class TestBoardAgent : public TestAgent{
public:
	TestBoardAgent();
	TestBoardAgent(BoardTest *p);
	virtual ~TestBoardAgent();

	void setBoardTest(BoardTest *p);
	virtual bool isTestOK();

protected:
	/***
	 * Task main run loop
	 */
	virtual void run();

	/***
	 * Get the static depth required in words
	 * @return - words
	 */
	virtual configSTACK_DEPTH_TYPE getMaxStackSize();

	bool xResult = false;

private:

	BoardTest *pTest = NULL;


};

#endif /* SRC_TESTBOARDAGENT_H_ */
