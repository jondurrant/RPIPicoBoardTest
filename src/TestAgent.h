/*
 * TestAgent.h
 *
 * Abstract Test Agent superclass
 *
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_TESTAGENT_H_
#define SRC_TESTAGENT_H_

#include "Agent.h"
#include "TestAgentInterface.h"

class TestAgent : public Agent, public TestAgentInterface {
public:
	TestAgent();
	virtual ~TestAgent();

	/***
	 * Start a test cycle
	 */
	virtual void startCycle();

	/***
	 * Check if the cycle is complete
	 * @return true if complete
	 */
	virtual bool isCycleComplete();

	/***
	 * Check if passed
	 * @return true - task passed
	 */
	virtual bool isTestOK();

	/***
	 * Get name of the test or in fact the task
	 * @return task name
	 */
	virtual const char * getName();

protected:
	bool xCycle = false;
};

#endif /* SRC_TESTAGENT_H_ */
