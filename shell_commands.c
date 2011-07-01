/**HEADER********************************************************************
*
* Copyright (c) 2008 Freescale Semiconductor;
* All Rights Reserved
*
* Copyright (c) 2004-2008 Embedded Access Inc.;
* All Rights Reserved
*
***************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
**************************************************************************
*
* $FileName: Shell_Commands.c$
* $Version : 3.6.9.0$
* $Date    : Jun-4-2010$
*
* Comments: Special commands created for demo
*
*END************************************************************************/
/*****************************************************************************
* Filename : shell_commands.c
* Modified by : T.J. Telan
* Date : 31 May 2011
*****************************************************************************/

#include "includes.h"
#include <string.h>
#include <shell.h>
#include "shell_commands.h"



/*FUNCTION*-------------------------------------------------------------------
*
* Function Name    :   Shell_set_time
* Returned Value   :  int_32 error code
* Comments  :  Sets Time
*
*END*---------------------------------------------------------------------*/

int_32  Shell_set_time(int_32 argc, char_ptr argv[] ){
    boolean           print_usage, shorthelp = FALSE;
    int_32            return_code = SHELL_EXIT_SUCCESS;
    TIME_STRUCT time;
    DATE_STRUCT date;
    int minute, hour;

    print_usage = Shell_check_help_request(argc, argv, &shorthelp );

    if (!print_usage) {
        if (argc !=2 ) {
            printf("Error, invalid number of parameters\n");
            return_code = SHELL_EXIT_ERROR;
            print_usage=TRUE;
        }
        else {
            if(argv[1][5]!='\0') {
                printf("Invalid Argument. Input should be HH:MM\n");
            }
            else {
                _time_get(&time);
                _time_to_date(&time,&date);
                hour=(argv[1][0]-0x30)*10 + (argv[1][1]-0x30);
                minute=(argv[1][3]-0x30)*10 + (argv[1][4]-0x30);

                if(hour>=24 || minute>=60) {
                    printf("Invalid Argument. Input should be HH:MM\n");
                }
                else {
                    date.HOUR=hour;
                    date.MINUTE=minute;
                    _time_from_date(&date,&time);
                    _time_set(&time);
                    _rtc_sync_with_mqx(FALSE);
                }
            }
        }
    }

    if (print_usage)  {
        print_usage_settime (shorthelp, argv[0], "<mode> - Select \"start\" or \"stop\"");
    }
    return return_code;
}

static void print_usage_settime (boolean shorthelp, const char_ptr argv, const char_ptr longhelp){
    if (shorthelp) {
        printf("%s <HH:MM>\n", argv);
    } else  {
        printf("Usage: %s <HH:MM>\n", argv);
        printf("   %s\n", longhelp);
    }
}


/* Unfortunately, did not finish these functions in time for the demo.
 * Figured I would leave them here so people could see what I was
 * aiming for */

//int_32 shell_toggle_gpio(int_32 argc, char_ptr argv[]){
//
//    if (!print_usage){}
//
//   if (print_usage)  {
//      print_usage_gpio (shorthelp, argv[0], "at the bottom of shell_toggle_gpio");
//   }
//   return return_code;
//}


//static void print_usage_gpio (boolean shorthelp, const char_ptr argv, const char_ptr longhelp)
//{
//  if (shorthelp)  {
//    printf("%s [portnumber]\n", argv);
//  } else  {
//    printf("Usage: %s [portnumber]\n", argv);
//    printf("   %s\n", longhelp);
//  }
//}


//int_32 shell_toggle_led(int_32 argc, char_ptr argv[]){
//    if (!print_usage){}
//
//   if (print_usage)  {
//      print_usage_led (shorthelp, argv[0], "at the bottom of shell_toggle_led");
//   }
//   return return_code;
//}


//static void print_usage_led (boolean shorthelp, const char_ptr argv, const char_ptr longhelp)
//{
//  if (shorthelp)  {
//    printf("%s [lednumber]\n", argv);
//  } else  {
//    printf("Usage: %s [lednumber]\n", argv);
//    printf("   %s\n", longhelp);
//  }
//}


//int_32 shell_toggle_all(int_32 argc, char_ptr argv[]){
//    if (!print_usage){}
//
//   if (print_usage)  {
//      print_usage_all (shorthelp, argv[0], "at the bottom of shell_toggle_all");
//   }
//   return return_code;
//}


//static void print_usage_all (boolean shorthelp, const char_ptr argv, const char_ptr longhelp)
//{
//  if (shorthelp)  {
//    printf("%s [on|off|invert]\n", argv);
//  } else  {
//    printf("Usage: %s [on|off|invert]\n", argv);
//    printf("   %s\n", longhelp);
//  }
//}

/* EOF*/
