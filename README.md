# CS467 RTOS Developement and Analysis
## freeRTOS implementation on the Tiva C Launchpad housing the TM4C123GH6PM Micro Controller

 - Implemented using Keil uVision5 Code Limited Version


 ### Before Compiling please take note of the following file modifications:
  - The following files 1 and 2 can be found in the root of the project - these files need to be used in place of the default files that come installed in the Keil software packs.

  1.  TM4C123GH6PM.h - Modified for use by bsp.c/h
    - dependancies(should be installed in system under Keil Software Packs):
        - core_CM4.h
        - system_TM4C123.h

  2. port.c - Added assembly in PendSV and BSP
    - This file is included in the Keil RTOS software pack
        - After downloading this source, ensure the project compiles with use of the original port.c file, then replace it in your filesystem with the version included in the root of this repository.




 Current Pin Utilization

| Pin Name | Direction | Function |
| -------- | -------- | -------- |
| PF1 | Output | Red LED |
| PF2 | Output | Blue LED and PendSV Signal to LA |
| PF3 | Output | Green LED and SysTick Signal to LA |
| PB3 | Output | Task 1 signal to LA |
| PC4 | Output | Task 2 signal to LA |
| PC5 | Output | Task 3 signal to LA |
| PC6 | Output  | Available |
| PC7 | Output | Available|
| PD6 | Output | Available |
| PD7 | Output | Available |
