/*
 * StepperTestAgent.h
 *
 *  Created on: 24 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_STEPPERTESTAGENT_H_
#define SRC_STEPPERTESTAGENT_H_

#include "Stepper28BYJ.h"
#include "TestAgentInterface.h"

class StepperTestAgent : public Stepper28BYJ , public TestAgentInterface {
public:
	/***
	 * Constructor
	 * @param gp1 - GPIO Pad
	 * @param gp2 - GPIO Pad
	 * @param gp3 - GPIO Pad
	 * @param gp4 - GPIO Pad
	 */
	StepperTestAgent(uint8_t gp1, uint8_t gp2, uint8_t gp3, uint8_t gp4 );

	virtual ~StepperTestAgent();

	virtual void startCycle();

	virtual bool isCycleComplete( );
	virtual bool isTestOK();

	virtual const char * getName();

private:

	bool xClockwise = true;
};

#endif /* SRC_STEPPERTESTAGENT_H_ */
