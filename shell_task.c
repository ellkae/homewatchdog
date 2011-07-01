/*****************************************************************************
* Filename : shell_task.c
* Author : T.J. Telan
* Date : 18 May 2011
*****************************************************************************/

#include "includes.h"
#include <shell.h>
#include "shell_commands.h"


/* Use:
 *  { "cmd_used_in_shell",  fcn_called_in_code }
 */
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
* Comments       : Shell can be used as an alternative controller (to the web controller)
*
*END------------------------------------------------------------------*/
void shell_task(uint_32 temp)
{
    printf("Starting Shell Task\n");

    /* Run the shell on the serial port */
    for(;;)
    {

        /* Start shell - accepts commands defined above 
         * Refer to MQX docs for shell specifics */
        Shell(shell_commands, NULL);
        printf("Shell exited, restarting...\n");
    }
}

/* EOF */
