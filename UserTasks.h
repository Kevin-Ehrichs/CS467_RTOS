/* User defined tasks for freeRTOS running on the EK-TM4C123GXL board */

#ifndef __USERTASKS_H__
#define __USERTASKS_H__

#include "bsp.h"
#include <stdint.h>
#include <FreeRTOS.h>
#include <task.h>


/* Function Prototypes */
void UserTask1(void *pvParameters);
void UserTask2(void *pvParameters);
void UserTask3(void *pvParameters);

#endif
