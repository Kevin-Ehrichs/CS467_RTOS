#ifndef __BSP_H__
#define __BSP_H__

/* Includes */
#include <stdint.h>  /* Standard integers. WG14/N843 C99 Standard */
#include "TM4C123GH6PM.h" /* the TM4C MCU Peripheral Access Layer (TI) */

/* system clock tick [Hz] */
#define BSP_TICKS_PER_SEC 1000U

/* LED States */
#define ON    1U
#define OFF   0U

/* GPIO Pin States */
#define HIGH  1U
#define LOW   0U  

/* GPIOs used in project */
#define GPIO_PF1  (1U << 1)
#define GPIO_PF2  (1U << 2)
#define GPIO_PF3  (1U << 3)

/* on-board LEDs */
#define LED_RED   GPIO_PF1
#define LED_BLUE  GPIO_PF2
#define LED_GREEN GPIO_PF3

void BSP_init(void);

void writeGPIOF_Pin(uint8_t GPIO, uint8_t state);

void BSP_setLED(uint8_t led, uint8_t state);

#endif // __BSP_H__
