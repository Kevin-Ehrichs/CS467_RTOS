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
#include "UserTasks.h"


<<<<<<< HEAD
int main()
=======
/* Toggle the PB3 pin at 3 second intervals */
void extraGPIOTask(void *pvParameters)
{
		/* Establish the task's period.*/
	const TickType_t xDelay = pdMS_TO_TICKS(3000);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	
	for (;;) {
		
		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, HIGH);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC4, HIGH);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC5, HIGH);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC6, HIGH);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC7, HIGH);
		vTaskDelayUntil(&xLastWakeTime, xDelay);

		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, LOW);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC4, LOW);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC5, LOW);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC6, LOW);
		BSP_setGPIO(GPIOC_AHB, GPIO_PC7, LOW);
		vTaskDelayUntil(&xLastWakeTime, xDelay);
	}
}

/* Blink red LED - 1 second intervals */
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

/* Blink blue LED - 1 second intervals */
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

/* Blink green LED - 1 second intervals */
void greenLEDTask(void *pvParameters)
>>>>>>> 9a9e628c91b2b1c6dee3229f1d32255d4a35e040
{
	
	/* 
	  About usStackDepth param - Each task has it's own stack - the usStackDepth parameter
	                              will define the size of the stack in words. In a later release, 
                                the program could use the function: uxTaskGetStackHighWaterMark 
																during runtime to programmatically infer the remaining memory
																stack available and adjust the tasks appropriately. 
	
		Solution for now is to assign the minimum number possible without crashing - perhaps we can pad this number for safety
		usStackDepth defined in multiples of 8 
	*/	
	xTaskCreate(UserTask1, "Toggle PB3 Pin", 32, NULL, 1, NULL);
	
	xTaskCreate(UserTask2, "Toggle PC4 Pin", 32, NULL, 1, NULL);
	
	xTaskCreate(UserTask3, "Toggle PC5 Pin", 32, NULL, 1, NULL);
	
	
	/* Initialize board level components inlcuding GPIO */
	BSP_init();
	

	/* Startup of the FreeRTOS scheduler.  The program should block here.  */
	vTaskStartScheduler();
	
	/* The following line should never be reached.  Failure to allocate enough
	  	memory from the heap would be one reason.*/
	for (;;);
}
