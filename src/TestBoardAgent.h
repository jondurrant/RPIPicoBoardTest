/*
 * TestBoardAgent.h
 *
 * Generic Test Agent that will run a BoardTest class
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

	/***
	 * Construct and provide test to run
	 * @param p - Test
	 */
	TestBoardAgent(BoardTest *p);
	virtual ~TestBoardAgent();

	/***
	 * Set the test to run
	 * @param p
	 */
	void setBoardTest(BoardTest *p);

	/***
	 * Check if test passed
	 * @return true if passed
	 */
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
