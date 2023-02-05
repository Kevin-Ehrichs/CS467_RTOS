#include "board_io.h"
#include "lm4f120h5qr.h" //map of named hardware addresses
#include "masks.h" //defined bit mask values
#include "TM4C123GH6PM.h"

const int BLINKY_MAX = 2000;
#define SYSTICKS_PER_SEC 1000;

void boardStartup(void)
{

  __asm("CPSID I"); //disable interrupts

  /////////////////////////////////////////////////////////////////
  // switched to using the AHB bus (faster)
  /////////////////////////////////////////////////////////////////
  SYSCTL->RCGCGPIO  |= (1U << 5); // enable Run mode for GPIOF */
  SYSCTL->GPIOHBCTL |= (1U << 5); // enable AHB for GPIOF */
  
  //make sure the Run Mode and AHB-enable take effects
  //before accessing the peripherals
  __ISB(); //Instruction Synchronization Barrier 
  __DSB(); //Data Memory Barrier 
  
  //systick stuff
  //SystemCoreClockUpdate();
  //SysTick_Config(SystemCoreClock / SYSTICKS_PER_SEC);

  NVIC_ST_RELOAD_R = (uint32_t)1000000U;     //set interval between systick interrupts (in clock cycles), I believe clock speed is 16 million cycles per second so this would be 16 interrupts per second
  NVIC_ST_CURRENT_R = (uint32_t)0;           //clear on write (so clears the counter value)
  NVIC_ST_CTRL_R = (uint32_t)0b00000111U;    //clock source, interrupt enable, counter enable

  //exception handler preemption priorty stuff
  //has the effect of setting pendsv to lowest priorty, 
  // RESERVED, and monitor interrupts to highest priority
      
  NVIC_SYS_PRI3_R = 0x00FF0000U;             
}
    

///////////////////////////////////////////////////////////////////
// Gotta get the Systick handler to manage the ticks on these
////////////////////////////////////////////////////////////////////
//assumes necessary initial setup completed to support blinking
void blinkRed()
{
    int direction = -1;
    int offset = BLINKY_MAX;
    while(1)
    {
      GPIO_PORTF_AHB_DATA_BITS_R[RED] = BYTE_BIT_ALL; //turn color on
      int i = -BLINKY_MAX;
      while(i < offset)
        ++i;        

      GPIO_PORTF_AHB_DATA_BITS_R[RED] = BYTE_BIT_NONE; //turn color off
      i = offset;
      while(i < BLINKY_MAX)
        ++i;        

      offset += direction;
      if(offset == BLINKY_MAX || offset == -BLINKY_MAX)
        direction *= -1;
    }
}

//assumes necessary initial setup completed to support blinking
void blinkBlue()
{
    int direction = 1;
    int offset = 0;
    while(1)
    {
      GPIO_PORTF_AHB_DATA_BITS_R[BLUE] = BYTE_BIT_ALL; //turn color on
      int i = -BLINKY_MAX;
      while(i < offset)
        ++i;        

      GPIO_PORTF_AHB_DATA_BITS_R[BLUE] = BYTE_BIT_NONE; //turn color off
      i = offset;
      while(i < BLINKY_MAX)
        ++i;  
      
      offset += direction;
      if (offset == BLINKY_MAX || offset == -BLINKY_MAX)
        direction *= -1;
    }
}

//assumes necessary initial setup completed to support blinking
void blinkGreen()
{
    int direction = 1;
    int offset = -BLINKY_MAX;
    while(1)
    {
      GPIO_PORTF_AHB_DATA_BITS_R[GREEN] = BYTE_BIT_ALL; //turn color on
      int i = -BLINKY_MAX;
      while(i < offset)
        ++i;        

      GPIO_PORTF_AHB_DATA_BITS_R[GREEN] = BYTE_BIT_NONE; //turn color off
      i = offset;
      while(i < BLINKY_MAX)
        ++i;  
      
      offset += direction;
      if (offset == BLINKY_MAX || offset == -BLINKY_MAX)
        direction *= -1;
    }
}