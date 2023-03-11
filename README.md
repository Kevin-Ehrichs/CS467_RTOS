# CS467 RTOS Developement and Analysis
## freeRTOS implementation on the Tiva C Launchpad housing the TM4C123GH6PM Micro Controller

 - Implemented using Keil uVision5 Code Limited Version


 ### Before Compiling please take note of the following file modifications:
  - The following files 1 and 2 can be found in the root of the project - these files need to be used in place of the default files that come installed in the Keil software packs.

  1.  TM4C123GH6PM.h - Modified for use by bsp.c/h
    - dependancies(should be installed in system under Keil Software Packs):
        - core_CM4.h
        - system_TM4C123.h

  2. port.c - Added assembly in PendSV and BSP calls to SysTick
    - This file is included in the Keil RTOS software pack but needs to be replaced by the custom version
        - After downloading this source, ensure the project compiles with use of the original port.c file, then replace it in your filesystem with the version included in the root of this repository.




 Current Pin Utilization

| Pin Name | Direction | Function |
| -------- | -------- | -------- |
| PF1 | Output | Red LED |
| PF2 | Output | Blue LED |
| PF3 | Output | Green LED |
| PB3 | Output | PendSV Signal to LA |
| PC4 | Output | SysTick Signal to LA |
| PC5 | Output | Task 1 Signal to LA |
| PC6 | Input  | Task 2 Signal to LA  |
| PC7 | Output | Task 3 Signal to LA  |
| PD6 | Output | Extra |
| PD7 | Output | Extra |
| PE5 | Output | UART Tx Line |
