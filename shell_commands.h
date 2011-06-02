/*****************************************************************************
* Filename : shell_commands.c
* Author : T.J. Telan
* Date : 18 May 2011
*****************************************************************************/

#include "includes.h"

int_32 Shell_set_time(int_32 argc, char_ptr argv[] );
int_32 shell_rtc_data(int_32 argc, char_ptr argv[]);
void print_usage_settime (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);
int_32 shell_toggle_gpio(int_32 argc, char_ptr argv[]);
void print_usage_gpio (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);
int_32 shell_toggle_led(int_32 argc, char_ptr argv[]);
void print_usage_led (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);
int_32 shell_toggle_all(int_32 argc, char_ptr argv[]);
void print_usage_all (boolean shorthelp, const char_ptr argv, const char_ptr longhelp);

/* EOF */
