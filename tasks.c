/*****************************************************************************
* Filename : tasks.c
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#include "includes.h"

#include <mqx.h>
#include <bsp.h> 
#include <fio.h>

#if ! BSPCFG_ENABLE_IO_SUBSYSTEM
#error This application requires BSPCFG_ENABLE_IO_SUBSYSTEM defined non-zero in user_config.h. Please recompile BSP with this option.
#endif


#ifndef BSP_DEFAULT_IO_CHANNEL_DEFINED
#error This application requires BSP_DEFAULT_IO_CHANNEL to be not NULL. Please set corresponding BSPCFG_ENABLE_TTYx to non-zero in user_config.h and recompile BSP with this option.
#endif


/* Task IDs */
#define START_TASK 5

extern void start_task(uint_32);


const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{ 
   /* Task Index,   Function,   Stack,  Priority, Name,     Attributes,          Param, Time Slice */
    { START_TASK,   start_task, 1500,   5,        "start",  MQX_AUTO_START_TASK, 0,     0 },
    { 0 }
};


#define GPIO1           (GPIO_PORT_C | GPIO_PIN18)
#define GPIO2           (GPIO_PORT_E | GPIO_PIN0)
#define GPIO3           (GPIO_PORT_E | GPIO_PIN28)
#define GPIO4           (GPIO_PORT_B | GPIO_PIN8)
#define GPIO5           (GPIO_PORT_E | GPIO_PIN28) // SD card is uses this port...
#define GPIO6           (GPIO_PORT_B | GPIO_PIN9)
#define GPIO7           (GPIO_PORT_E | GPIO_PIN27)
#define GPIO8           (GPIO_PORT_E | GPIO_PIN5)
#define GPIO9           (GPIO_PORT_C | GPIO_PIN19)
#define BSP_LED1        (GPIO_PORT_A | GPIO_PIN11)
#define BSP_LED2        (GPIO_PORT_A | GPIO_PIN28)
#define BSP_LED3        (GPIO_PORT_A | GPIO_PIN29)
#define BSP_LED4        (GPIO_PORT_A | GPIO_PIN10)
/*----------------------------------------------------------------------------
- Task Name : start_task
- Comments :
----------------------------------------------------------------------------*/

void start_task(uint_32 initial_data){
   printf("Hello World\n"); 
   
    FILE_PTR output_port;

    const uint_32 output_set[] = {
        GPIO1,
        GPIO2,
        GPIO3,
        GPIO4,
        GPIO5,
        GPIO6,
        GPIO7,
        GPIO8,
        GPIO9,
        BSP_LED1,
        BSP_LED2,

        BSP_LED4,
        GPIO_LIST_END
  };
  
  // Set GPIO array as outputs
  output_port = fopen("gpio:write", (char_ptr) &output_set);
  
  
  if (output_port){
        printf("Turn ons?\n");
        ioctl(output_port, GPIO_IOCTL_WRITE_LOG0, &output_port);

  }
   /* 
   ** This example uses polled serial I/O by default. Should it be modified
   ** to use interrupt driven serial drivers, you will need to uncomment the
   ** following delay code to insure serial communication completes before 
   ** _mqx_exit() disables all interrupts.
   */
  _time_delay(200);
   
   _mqx_exit(0);

}

/* EOF */
