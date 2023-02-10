/* Board Support Package (BSP) for the EK-TM4C123GXL board */

/* This file uses a custom "TM4C123GH6PM.h" file that should be included in the project. */
#include "bsp.h"


void BSP_init(void) {
	
		/* Goal is to have available, extra GPIO to be used for logic analyzer testing.
	     The GPIOs located on J4 Connector of TivaC are marked as digital GPIO and  all
	     having interrupt capability. The selection was also used, as these pins do
	     not share any common functionality such as serial communication or Analog ability
	     This selection allows for the most flexibility in terms of future developement */
	
		/* Enable Run mode for the following GPIO Rails */
	  /* TM4C123GXL_datasheet - pg. 340 - Register 60 - General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO) */
	  SYSCTL->RCGCGPIO  |= (GPIOF_BF | GPIOB_BF | GPIOC_BF | GPIOD_BF);
	
		/* Connect the GPIO rails to the high performance AHB bus */
		/* TM4C123GXL_datasheet - pg. 258 - Register 9 - GPIO High-Performance Bus Control (GPIOHBCTL) */
	  SYSCTL->GPIOHBCTL |= (GPIOF_BF | GPIOB_BF | GPIOC_BF | GPIOD_BF);


    /* make sure the Run Mode and AHB-enable take effects
    *  before accessing the peripherals */
    __ISB(); /* Instruction Synchronization Barrier */
    __DSB(); /* Data Memory Barrier */

    GPIOF_AHB->DIR |= (GPIO_PF1 | GPIO_PF2 | GPIO_PF3); /* Set GPIOs used in F rail as outputs */
		GPIOB_AHB->DIR |= (GPIO_PB3);
		GPIOC_AHB->DIR |= (GPIO_PC4 | GPIO_PC5 | GPIO_PC6 | GPIO_PC7);
		GPIOD_AHB->DIR |= (GPIO_PD6 | GPIO_PD7);
		
		
    GPIOF_AHB->DEN |= (GPIO_PF1 | GPIO_PF2 | GPIO_PF3); /* Enable GPIOs used in F rail */
		GPIOB_AHB->DEN |= (GPIO_PB3);
		GPIOC_AHB->DEN |= (GPIO_PC4 | GPIO_PC5 | GPIO_PC6 | GPIO_PC7);
		GPIOD_AHB->DEN |= (GPIO_PD6 | GPIO_PD7);

    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / BSP_TICKS_PER_SEC);

    __enable_irq();
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

/* Abstraction for setting the state of a GPIO on Rail B */
/* param GPIO, the GPIO being set (GPIO_PFx)  */
/* param state, HIGH or LOW                   */
void writeGPIOB_Pin(uint8_t GPIO, uint8_t state){
	   
		if(state == 1){ /* Set high */
			GPIOB_AHB->DATA_Bits[GPIO] = GPIO;	
		}
		else{ /*  all other conditions set low */
			GPIOB_AHB->DATA_Bits[GPIO] = 0U;	
		}
}

/* Abstraction for setting the state of a GPIO on Rail C */
/* param GPIO, the GPIO being set (GPIO_PFx)  */
/* param state, HIGH or LOW                   */
void writeGPIOC_Pin(uint8_t GPIO, uint8_t state){
	   
		if(state == 1){ /* Set high */
			GPIOC_AHB->DATA_Bits[GPIO] = GPIO;	
		}
		else{ /*  all other conditions set low */
			GPIOC_AHB->DATA_Bits[GPIO] = 0U;	
		}
}

/* Abstraction for setting the state of a GPIO on Rail D */
/* param GPIO, the GPIO being set (GPIO_PFx)  */
/* param state, HIGH or LOW                   */
void writeGPIOD_Pin(uint8_t GPIO, uint8_t state){
	   
		if(state == 1){ /* Set high */
			GPIOD_AHB->DATA_Bits[GPIO] = GPIO;	
		}
		else{ /*  all other conditions set low */
			GPIOD_AHB->DATA_Bits[GPIO] = 0U;	
		}
}






/* Abstraction for setting the state of an LED on the TivaC Launchpad Board */
/* param led, the led being set (LED_x) */
/* param state, ON or Off  */
void BSP_setLED(uint8_t led, uint8_t state)
{
	writeGPIOF_Pin(led, state);
}
