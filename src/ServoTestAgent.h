/*
 * ServoTestAgent.h
 *
 *  Created on: 23 Oct 2023
 *      Author: jondurrant
 */

#ifndef SRC_SERVOTESTAGENT_H_
#define SRC_SERVOTESTAGENT_H_

#include "TestAgent.h"
#include "Servo.h"

#define MAX_SERVOS 5

class ServoTestAgent : public TestAgent{
public:
	ServoTestAgent();
	virtual ~ServoTestAgent();

	void addServo(uint8_t gpio);

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

private:
	Servo xServos[MAX_SERVOS];
	int xNumServos = 0;


};

#endif /* SRC_SERVOTESTAGENT_H_ */
