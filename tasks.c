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



const TASK_TEMPLATE_STRUCT  MQX_template_list[] = 
{ 
   /* Task Index,   Function,   Stack,  Priority, Name,     Attributes,          Param, Time Slice */
    { START_TASK,   start_task, 1500,   5,        "start",  MQX_AUTO_START_TASK, 0,     0 },
    { SDCARD_TASK,   sdcard_task,      1500,    11,      "SDcard", 0, 0,     0 },
    { SHELL_TASK,    shell_task,       1500,    14,      "Shell",  0, 0,     0 },

    { 0 }
};



/* EOF */
