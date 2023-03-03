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


int main()
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
