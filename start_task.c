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

    /* Setup GPIO */
    initializeIO();

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