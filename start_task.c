/*****************************************************************************
* Filename : start_task.c
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#include "includes.h"
#include "homewatchdog.h"

/*----------------------------------------------------------------------------
- Task Name : start_task
- Comments :
----------------------------------------------------------------------------*/

void start_task(uint_32 initial_data){
   printf("Starting Start Task\n"); 
   
    FILE_PTR output_port;

    const uint_32 output_set[] = {
//        GPIO1 | GPIO_PIN_STATUS_1,
//        GPIO2 | GPIO_PIN_STATUS_1,
//        GPIO3 | GPIO_PIN_STATUS_1,
//        GPIO4 | GPIO_PIN_STATUS_1,
//        GPIO5 | GPIO_PIN_STATUS_1,
//        GPIO6 | GPIO_PIN_STATUS_1,
//        GPIO7 | GPIO_PIN_STATUS_1,
//        GPIO8 | GPIO_PIN_STATUS_1,
//        GPIO9 | GPIO_PIN_STATUS_1,
        BSP_LED1 | GPIO_PIN_STATUS_0,
        BSP_LED2 | GPIO_PIN_STATUS_0,
        BSP_LED3 | GPIO_PIN_STATUS_0,
        BSP_LED4 | GPIO_PIN_STATUS_0,
        GPIO_LIST_END
  };
  
  // Set GPIO array as outputs
  output_port = fopen("gpio:write", (char_ptr) &output_set);
  
  
  if (output_port){
        ioctl(output_port, GPIO_IOCTL_WRITE_LOG1, &output_port);

  }
  
    /* Setup GPIO */
    InitializeIO();


    /* Create sd card task */
    _task_create(0,SDCARD_TASK,0);
  
    /* Create shell task */
    _task_create(0,SHELL_TASK,0);
  
    /* Set up networking and web server */
    initialize_networking();

     /* Block forever since init done */
    _task_block();


}

/* EOF */