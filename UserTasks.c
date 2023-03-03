/* User defined tasks for freeRTOS running on the EK-TM4C123GXL board */


#include "UserTasks.h"

/* 
	 Boilerplate tasks for signaling to the logic 
	 analyzer in order to test freeRTOS metrics
*/

/* Signaling - PB3 */
void UserTask1(void *pvParameters)
{
	/* 
	  No Delay is being used at this time - to introduce a delay:
			- uncomment the below 3 lines, then move
      	vTaskDelayUntil function where needed
	*/
	//const TickType_t xDelay = pdMS_TO_TICKS(10);
	//TickType_t xLastWakeTime = xTaskGetTickCount();
	//vTaskDelayUntil(&xLastWakeTime, xDelay);
	
	for (;;) {
		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, HIGH); /**SIGNAL Start of Task TO LA */

		BSP_setGPIO(GPIOB_AHB, GPIO_PB3, LOW); /*SIGNAL End of Task TO LA */
	}
}	

/* Signaling - PC4 */
void UserTask2(void *pvParameters)
{
	for (;;) {
		BSP_setGPIO(GPIOC_AHB, GPIO_PC4, HIGH); /**SIGNAL Start of Task TO LA */
		
		BSP_setGPIO(GPIOC_AHB, GPIO_PC4, LOW); /**SIGNAL End of Task TO LA */
	}
}	

/* Signaling - PC5 */
void UserTask3(void *pvParameters)
{	
	for (;;) {
		BSP_setGPIO(GPIOC_AHB, GPIO_PC5, HIGH); /**SIGNAL TO LA */

		BSP_setGPIO(GPIOC_AHB, GPIO_PC5, LOW); /**SIGNAL TO LA */
	}
}	
