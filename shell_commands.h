/*****************************************************************************
* Filename : shell_commands.h
* Author : T.J. Telan
* Date : 18 May 2011
*****************************************************************************/

#include "includes.h"

/* Set the system clock */
int_32 Shell_set_time(int_32 argc, char_ptr argv[] );

/* Get the system clock */
int_32 shell_rtc_data(int_32 argc, char_ptr argv[]);

/* Short help doc on how to use the set time shell command */
void print_usage_settime (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);

/* GPIO port control command */
int_32 shell_toggle_gpio(int_32 argc, char_ptr argv[]);

/* Short help doc on how to use the toggle gpio shell command */
void print_usage_gpio (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);

/* LED port control command */
int_32 shell_toggle_led(int_32 argc, char_ptr argv[]);

/* Short help doc on how to use the toggle led shell command */
void print_usage_led (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);

/* Send command to both LED + GPIO ports */
int_32 shell_toggle_all(int_32 argc, char_ptr argv[]);

/* Short help doc on how to use the toggle all shell command */
void print_usage_all (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);

/* EOF */
