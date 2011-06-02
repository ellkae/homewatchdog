/*****************************************************************************
* Filename : shell_task.c
* Author : T.J. Telan
* Date : 18 May 2011
*****************************************************************************/

#include "includes.h"
#include <shell.h>
#include "shell_commands.h"


const SHELL_COMMAND_STRUCT shell_commands[] = {
    { "settime",    Shell_set_time },
    { "exit",       Shell_exit },
//    { "gpio",       shell_toggle_gpio},
//    { "led",        shell_toggle_led},
//    { "all",        shell_toggle_all},
    { "?",          Shell_command_list },
    { NULL,         NULL }
};



/*TASK*-----------------------------------------------------------------
*
* Function Name  : shell_task
* Returned Value : void
* Comments       :
*
*END------------------------------------------------------------------*/
void shell_task(uint_32 temp)
{
    printf("Starting Shell Task\n");

    /* Run the shell on the serial port */
    for(;;)
    {
        // Need to define some shell commands first...
        Shell(shell_commands, NULL);
        printf("Shell exited, restarting...\n");
    }
}

/* EOF */