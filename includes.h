/*****************************************************************************
* Filename : includes.h
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#ifndef _includes_h_
#define _includes_h_

/* OS + IO drivers */
#include <mqx.h>
#include <bsp.h> 

/* Networking */
#include <rtcs.h>
#include "ifconfig.h"

/* Filesystem */
#include <fio.h>

/* GPIO port defines */
#include <io_gpio.h>

/* Share GPIO_t with everyone */
#include "homewatchdog.h"

/* Macros */
// True/False == 1/0
#define ON      TRUE
#define OFF     FALSE

/* Project GPIO defines */
#define USR_GPIO1       (GPIO_PORT_C | GPIO_PIN0)
#define USR_GPIO2       (GPIO_PORT_C | GPIO_PIN1)
#define USR_GPIO3       (GPIO_PORT_C | GPIO_PIN2)
#define USR_GPIO4       (GPIO_PORT_C | GPIO_PIN3)
#define USR_GPIO5       (GPIO_PORT_C | GPIO_PIN4)
#define USR_GPIO6       (GPIO_PORT_C | GPIO_PIN5)
#define USR_GPIO7       (GPIO_PORT_C | GPIO_PIN6)
#define USR_GPIO8       (GPIO_PORT_C | GPIO_PIN7)
#define USR_GPIO9       (GPIO_PORT_C | GPIO_PIN8)
#define BSP_LED1        (GPIO_PORT_A | GPIO_PIN11)
#define BSP_LED2        (GPIO_PORT_A | GPIO_PIN28)
#define BSP_LED3        (GPIO_PORT_A | GPIO_PIN29)
#define BSP_LED4        (GPIO_PORT_A | GPIO_PIN10)

/* Task Numbers */
#define START_TASK  1
#define SDCARD_TASK 5
#define SHELL_TASK  10

/* Prototype for Tasks */
extern void start_task(uint_32);
extern void sdcard_task(uint_32);
extern void shell_task(uint_32);


#endif
