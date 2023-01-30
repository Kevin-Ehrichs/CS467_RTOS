#include <stdint.h>

#include "board_io.h" //for the blink functions
#include "ticks.h" //for resetTicks()
#include "lm4f120h5qr.h" //map of named hardware addresses
#include "masks.h" //defined bit mask values
#include "unicorn.h"


int main()
{ 

  __asm("CPSID I"); //disable interrupts

  //gpio f stuff
  SYSCTL_RCGCGPIO_R |= OPEN_GPIOF_CLOCK_GATE_MASK; //open clock gating to GPIO port F  
  GPIO_PORTF_DIR_R |= SET_GPIO_PIN_TO_OUTPUT_MASK; //set GPIO port F pins' direction to output  
  GPIO_PORTF_DEN_R |= SET_GPIO_PIN_TO_DIGITAL_MASK; //set GPIO port F pins' type to digital  
  
  //systick stuff
  NVIC_ST_RELOAD_R = (uint32_t)1000000U; //set interval between systick interrupts (in clock cycles), I believe clock speed is 16 million cycles per second so this would be 16 interrupts per second
  NVIC_ST_CURRENT_R = (uint32_t)0; //clear on write (so clears the counter value)
  NVIC_ST_CTRL_R = (uint32_t)0b00000111U; //clock source, interrupt enable, counter enable

  //exception handler preemption priorty stuff
  NVIC_SYS_PRI3_R = 0x00FF0000U; //has the effect of setting pendsv to lowest priorty, systick, RESERVED, and monitor interrupts to highest priority
      
      
  //OS stuff
  initializeScheduler();
  
  //***start tasks here***
  readyNewTask(&blinkRed);
  readyNewTask(&blinkBlue);
  readyNewTask(&blinkGreen);
  
  resetTicks(); //set starting number of ticks to 0

  __asm("CPSIE I"); //enable interrupts
  
  //***from this point, the systick interrupt handler will begin executing and will cause scheduling of processes**
  
  while(1);

  return 0;
}