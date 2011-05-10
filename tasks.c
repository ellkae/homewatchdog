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



/*----------------------------------------------------------------------------
- Task Name : start_task
- Comments :
----------------------------------------------------------------------------*/

void start_task(uint_32 initial_data){
   printf("Hello World\n"); 
   
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
