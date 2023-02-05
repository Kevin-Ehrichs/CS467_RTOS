/* Board Support Package (BSP) for the EK-TM4C123GXL board */

/* This file uses a custom "TM4C123GH6PM.h" file that should be included in the project. */
#include "bsp.h"


void BSP_init(void) {
    SYSCTL->RCGCGPIO  |= (1U << 5); /* enable Run Mode for GPIOF */
    SYSCTL->GPIOHBCTL |= (1U << 5); /* enable AHB for GPIOF */

    /* make sure the Run Mode and AHB-enable take effects
    * before accessing the peripherals
    */
    __ISB(); /* Instruction Synchronization Barrier */
    __DSB(); /* Data Memory Barrier */

    GPIOF_AHB->DIR |= (GPIO_PF1 | GPIO_PF2 | GPIO_PF3); /* Set GPIOs used in F rail as outputs */
    GPIOF_AHB->DEN |= (GPIO_PF1 | GPIO_PF2 | GPIO_PF3); /* Enable GPIOs used in F rail */


    /* THE SYSTEMCORECLOCKUPDATE() FUNCTION APPEARS TO BE DEPENDEDENT ON SOME FREERTOS STUFF
     * SO IF WE LATER INCORPORATE THE BSP_INIT DEFINED HERE INTO THE FREERTOS SIDE, THIS WILL NEED REVISION */

    //SystemCoreClockUpdate();
    //SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);
    NVIC_ST_RELOAD_R = (uint32_t)1000000U;     //set interval between systick interrupts (in clock cycles), I believe clock speed is 16 million cycles per second so this would be 16 interrupts per second
    NVIC_ST_CURRENT_R = (uint32_t)0;           //clear on write (so clears the counter value)
    NVIC_ST_CTRL_R = (uint32_t)0b00000111U;    //clock source, interrupt enable, counter enable
}

/* Abstraction for setting the state of a GPIO on Rail F */
/* param GPIO, the GPIO being set (GPIO_PFx) */
/* param state, HIGH or LOW                   */
void writeGPIOF_Pin(uint8_t GPIO, uint8_t state){
	   
		if(state == 1){ /* Set high */
			GPIOF_AHB->DATA_Bits[GPIO] = GPIO;	
		}
		else{ /*  all other conditions set low */
			GPIOF_AHB->DATA_Bits[GPIO] = 0U;	
		}
}

/* Abstraction for setting the state of an LED on the TivaC Launchpad Board */
/* param led, the led being set (LED_x) */
/* param state, ON or Off  */
void BSP_setLED(uint8_t led, uint8_t state)
{
	writeGPIOF_Pin(led, state);
}
