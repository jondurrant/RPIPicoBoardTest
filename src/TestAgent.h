/*
 * TestAgent.h
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

	virtual void startCycle();

	virtual bool isCycleComplete();
	virtual bool isTestOK();

	virtual const char * getName();

protected:
	bool xCycle = false;
};

#endif /* SRC_TESTAGENT_H_ */
