/*
 * TestAgentInterface.h
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

	virtual void startCycle() =0;

	virtual bool isCycleComplete( ) =0;
	virtual bool isTestOK() =0;

	virtual const char * getName() = 0;
};

#endif /* SRC_TESTAGENTINTERFACE_H_ */
