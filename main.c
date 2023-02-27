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

#define GPIO_PORTF_DATA_R (*(( volatile unsigned long *)0x40025038 ) ) 

/**** TASK DEFINITIONS ****/


/* Blink red LED - 1 second intervals */
void redLEDTask(void *pvParameters)
{
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(10);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, HIGH); /**SIGNAL TO LA */
		//BSP_setLED(LED_RED, ON);
		//xTaskDelayUntil(&xLastWakeTime, xDelay);

		//BSP_setLED(LED_RED, OFF);
		//xTaskDelayUntil(&xLastWakeTime, xDelay);
		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, LOW); /**SIGNAL TO LA */
	}
}	

/* Blink blue LED - 1 second intervals */
void blueLEDTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(1000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, HIGH); /**SIGNAL TO LA */
		//BSP_setLED(LED_BLUE, ON);
		//xTaskDelayUntil(&xLastWakeTime, xDelay);
		
		//BSP_setLED(LED_BLUE, OFF);
		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, LOW); /**SIGNAL TO LA */
		//xTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}	

/* Blink green LED - 1 second intervals */
void greenLEDTask(void *pvParameters)
{
	
	/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(10);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		BSP_setGPIO(GPIOC_AHB, GPIO_PC4, HIGH); /**SIGNAL TO LA */
		//BSP_setLED(LED_GREEN, ON);
		//xTaskDelayUntil(&xLastWakeTime, xDelay);
		
		//BSP_setLED(LED_GREEN, OFF);
		//xTaskDelayUntil(&xLastWakeTime, xDelay);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC4, LOW); /**SIGNAL TO LA */
	}
}	


int main()
{
	/* Need to understand usStackDepth and how much we really need */
	/* 32 seems to be minimum for current task implementation      */
	//xTaskCreate(redLEDTask, "RED LED", 32, NULL, 1, NULL);
	
	xTaskCreate(blueLEDTask, "BLUE LED", 32, NULL, 1, NULL);
	
	xTaskCreate(greenLEDTask, "GREEN LED", 32, NULL, 1, NULL);
	
	
	/* Initialize board level components inlcuding GPIO */
	BSP_init();
	

	/* Startup of the FreeRTOS scheduler.  The program should block here.  */
	vTaskStartScheduler();
	
	/* The following line should never be reached.  Failure to allocate enough
	  	memory from the heap would be one reason.*/
	for (;;);
}
