/*
 * TestAgentInterface.h
 *
 * Standard interface for manage Test Agents
 *
 *  Created on: 24 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_TESTAGENTINTERFACE_H_
#define SRC_TESTAGENTINTERFACE_H_

class TestAgentInterface {
public:
	TestAgentInterface();
	virtual ~TestAgentInterface();

	/***
	 * Start a test cycle
	 */
	virtual void startCycle() =0;

	/***
	 * Check if the test is complete
	 * @return true if complete
	 */
	virtual bool isCycleComplete( ) =0;

	/***
	 * Check is the test passed
	 * @return true if passed
	 */
	virtual bool isTestOK() =0;

	/***
	 * Get the name of the test or task
	 * @return task name
	 */
	virtual const char * getName() = 0;
};

#endif /* SRC_TESTAGENTINTERFACE_H_ */
