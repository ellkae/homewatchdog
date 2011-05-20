/*****************************************************************************
* Filename : includes.h
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#ifndef _includes_h_
#define _includes_h_

#include <mqx.h>
#include <bsp.h> 
#include <fio.h>

#include <rtcs.h>
#include "ipconfig.h"

#include <io_gpio.h>

#include "homewatchdog.h"

/* Macros */
// True/False == 1/0
#define ON      TRUE
#define OFF     FALSE

#define GPIO1           (GPIO_PORT_C | GPIO_PIN0)
#define GPIO2           (GPIO_PORT_C | GPIO_PIN1)
#define GPIO3           (GPIO_PORT_C | GPIO_PIN2)
#define GPIO4           (GPIO_PORT_C | GPIO_PIN3)
#define GPIO5           (GPIO_PORT_C | GPIO_PIN4)
#define GPIO6           (GPIO_PORT_C | GPIO_PIN5)
#define GPIO7           (GPIO_PORT_C | GPIO_PIN6)
#define GPIO8           (GPIO_PORT_C | GPIO_PIN7)
#define GPIO9           (GPIO_PORT_C | GPIO_PIN8)
#define BSP_LED1        (GPIO_PORT_A | GPIO_PIN11)
#define BSP_LED2        (GPIO_PORT_A | GPIO_PIN28)
#define BSP_LED3        (GPIO_PORT_A | GPIO_PIN29)
#define BSP_LED4        (GPIO_PORT_A | GPIO_PIN10)

/* Task Numbers */
#define START_TASK  1
#define SDCARD_TASK 5
#define SHELL_TASK  10

/* Global Variables */

/* Prototype for Tasks */
extern void start_task(uint_32);
extern void sdcard_task(uint_32);
extern void shell_task(uint_32);


#endif