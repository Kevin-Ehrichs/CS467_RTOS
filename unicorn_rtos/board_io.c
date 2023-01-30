#include "board_io.h"
#include "lm4f120h5qr.h" //map of named hardware addresses
#include "masks.h" //defined bit mask values

const int BLINKY_MAX = 2000;


//note: the relative address of each element of DATA_BITS_R array acts as a bit mask for the input
//being applied in assignment operation allowing faster bitwise setting control, so only the bits
//on the actual data register corresponding to the bits of the relative address are modified

//assumes necessary initial setup completed to support blinking
void blinkRed()
{
    int direction = -1;
    int offset = BLINKY_MAX;
    while(1)
    {
      GPIO_PORTF_DATA_BITS_R[RED] = BYTE_BIT_ALL; //turn color on
      int i = -BLINKY_MAX;
      while(i < offset)
        ++i;        

      GPIO_PORTF_DATA_BITS_R[RED] = BYTE_BIT_NONE; //turn color off
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
      GPIO_PORTF_DATA_BITS_R[BLUE] = BYTE_BIT_ALL; //turn color on
      int i = -BLINKY_MAX;
      while(i < offset)
        ++i;        

      GPIO_PORTF_DATA_BITS_R[BLUE] = BYTE_BIT_NONE; //turn color off
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
      GPIO_PORTF_DATA_BITS_R[GREEN] = BYTE_BIT_ALL; //turn color on
      int i = -BLINKY_MAX;
      while(i < offset)
        ++i;        

      GPIO_PORTF_DATA_BITS_R[GREEN] = BYTE_BIT_NONE; //turn color off
      i = offset;
      while(i < BLINKY_MAX)
        ++i;  
      
      offset += direction;
      if (offset == BLINKY_MAX || offset == -BLINKY_MAX)
        direction *= -1;
    }
}