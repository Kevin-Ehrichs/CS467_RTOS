/****************************************************************************************************//**
 * @file     main.c
 *
 * @brief    freeRTOS Implementation on the TivaC Launchpad (TM4C123GH6PM)
 *
 * @date     10 Feb. 2023
 *
 *******************************************************************************************************/
#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>
#include "bsp.h"

void extraGPIOTask(void *pvParameters)
{
		/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		
		writeGPIOC_Pin(GPIO_PC4, HIGH);
		vTaskDelayUntil(&xLastWakeTime, xDelay);

		writeGPIOC_Pin(GPIO_PC4, LOW);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
	
}

/* Task Definitions */
void redLEDTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		
		BSP_setLED(LED_RED, ON);
		vTaskDelayUntil(&xLastWakeTime, xDelay);

		BSP_setLED(LED_RED, OFF);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}

}	

void blueLEDTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_setLED(LED_BLUE, ON);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		
		BSP_setLED(LED_BLUE, OFF);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}	

void greenLEDTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_setLED(LED_GREEN, ON);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
		
		BSP_setLED(LED_GREEN, OFF);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}	


int main()
{
	/* Need to understand usStackDepth and how much we really need */
	/* 32 seems to be minimum for current task implementation      */
	xTaskCreate(redLEDTask, "RED LED", 32, NULL, 1, NULL);
	
	xTaskCreate(blueLEDTask, "BLUE LED", 32, NULL, 1, NULL);
	
	xTaskCreate(greenLEDTask, "GREEN LED", 32, NULL, 1, NULL);
	
	xTaskCreate(extraGPIOTask, "Extra GPIO", 32, NULL, 1, NULL);
	
	/* Initialize board level components inlcuding GPIO */
	BSP_init();

	/* Startup of the FreeRTOS scheduler.  The program should block here.  */
	vTaskStartScheduler();
	
	/* The following line should never be reached.  Failure to allocate enough
	  	memory from the heap would be one reason.*/
	for (;;);
}
