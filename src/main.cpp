/***
 * main.cpp - Test PCB
 * Jon Durrant
 * 4-Oct-2022
 *
 *
 */

#include <cstdio>


#include "FreeRTOS.h"
#include "task.h"

#include "PicoOnboardLED.h"
#include "LEDsTest.h"
#include "ADCComp.h"
#include "HCSR04Comp.h"
#include "ServoTest.h"
#include "ServoTestAgent.h"
#include "TestBoardAgent.h"


#define TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )


void runTimeStats(){
  TaskStatus_t         * pxTaskStatusArray;
  volatile UBaseType_t uxArraySize, x;
  unsigned long        ulTotalRunTime;


  /* Take a snapshot of the number of tasks in case it changes while this
  function is executing. */
  uxArraySize = uxTaskGetNumberOfTasks();
  printf("Number of tasks %d\n", uxArraySize);

  /* Allocate a TaskStatus_t structure for each task.  An array could be
  allocated statically at compile time. */
  pxTaskStatusArray = (TaskStatus_t*) pvPortMalloc(uxArraySize * sizeof(TaskStatus_t));

  if (pxTaskStatusArray != NULL){
    /* Generate raw status information about each task. */
    uxArraySize = uxTaskGetSystemState(pxTaskStatusArray,
                                       uxArraySize,
                                       &ulTotalRunTime);



    /* For each populated position in the pxTaskStatusArray array,
    format the raw data as human readable ASCII data. */
    for (x = 0; x < uxArraySize; x++){
      printf("Task: %d \t cPri:%d \t bPri:%d \t hw:%d \t%s\n",
             pxTaskStatusArray[x].xTaskNumber,
             pxTaskStatusArray[x].uxCurrentPriority,
             pxTaskStatusArray[x].uxBasePriority,
             pxTaskStatusArray[x].usStackHighWaterMark,
             pxTaskStatusArray[x].pcTaskName
      );
    }


    /* The array is no longer needed, free the memory it consumes. */
    vPortFree(pxTaskStatusArray);
  } else{
    printf("Failed to allocate space for stats\n");
  }

  HeapStats_t heapStats;
  vPortGetHeapStats(&heapStats);
  printf("HEAP avl: %d, blocks %d, alloc: %d, free: %d\n",
         heapStats.xAvailableHeapSpaceInBytes,
         heapStats.xNumberOfFreeBlocks,
         heapStats.xNumberOfSuccessfulAllocations,
         heapStats.xNumberOfSuccessfulFrees
  );

}


void main_task(void* params){
	PicoOnboardLED onboardLED;
	LEDsTest leds;
	ADCComp adc;
	//HCSR04Comp hcsr04(10, 11, 10, 80);
	//HCSR04Comp hcsr04(8, 9, 10, 80);
	HCSR04Comp hcsr04(6, 7, 10, 80);
	TestBoardAgent ledAgent(&leds);
	TestBoardAgent adcAgent(&adc);
	TestBoardAgent onboardAgent(&onboardLED);
	TestBoardAgent hcsr04Agent(&hcsr04);

	ServoTestAgent servos;

	printf("Main task started\n");

	servos.addServo(22);
	servos.addServo(21);
	servos.addServo(20);
	servos.addServo(19);
	servos.addServo(18);

  leds.addLed(1, 0);
  leds.addLed(2, 1);
  leds.addLed(3, 2);
  leds.addLed(4, 3);
  leds.addLed(5, 4);


  adc.addADC(26, 2.2, 2.6);
  adc.addADC(27,  1.3, 1.8);
  adc.addADC(28,  0.6,  1.1);

  servos.start("Servos", TASK_PRIORITY);
  ledAgent.start("LEDs", TASK_PRIORITY);
  adcAgent.start("ADC", TASK_PRIORITY);
  onboardAgent.start("Onboard LED", TASK_PRIORITY);
  hcsr04Agent.start("LEDs", TASK_PRIORITY);

  for(;;){

	  for (int i=0; i < 10; i++){
		  servos.startCycle();
		  ledAgent.startCycle();
		  adcAgent.startCycle();
		  onboardAgent.startCycle();
		  hcsr04Agent.startCycle();

		  vTaskDelay(10000);
	  }

    runTimeStats();

  }

}


void vLaunch(void) {
  TaskHandle_t task;

  xTaskCreate(main_task, "MainThread", 2048, NULL, TASK_PRIORITY, &task);

  /* Start the tasks and timer running. */
  vTaskStartScheduler();
}


int main(void) {
  stdio_init_all();
  sleep_ms(2000);
  printf("GO\n");

  /* Configure the hardware ready to run the demo. */
  const char* rtos_name;
  rtos_name = "FreeRTOS";
  printf("Starting %s on core 0:\n", rtos_name);
  vLaunch();

  return 0;
}
