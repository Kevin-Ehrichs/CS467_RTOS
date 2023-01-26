#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>
#include "bsp.h"

void vPeriodicTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_ledGreenOn();
		
		/* Block until the next release time.*/
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		
		BSP_ledGreenOff();
		
	  /* Block until the next release time.*/
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}

}	

void vvPeriodicTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_ledBlueOn();
		
		/* Block until the next release time.*/
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		
		BSP_ledBlueOff();
		
	  /* Block until the next release time.*/
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}

}	

void vvvPeriodicTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_ledRedOn();
		
		/* Block until the next release time.*/
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		
		BSP_ledRedOff();
		
	  /* Block until the next release time.*/
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}

}	



int main()
{
	
	xTaskCreate(vPeriodicTask, "My Task", 256, NULL, 1, NULL);
	xTaskCreate(vvPeriodicTask, "My Task", 256, NULL, 1, NULL);
	//xTaskCreate(vvvPeriodicTask, "My Task", 256, NULL, 1, NULL);
	
	BSP_init();
	
	BSP_ledGreenOn();

	/* Startup of the FreeRTOS scheduler.  The program should block here.  */
	vTaskStartScheduler();
	
	/* The following line should never be reached.  Failure to allocate enough
	  	memory from the heap would be one reason.*/
	for (;;);
	
}
