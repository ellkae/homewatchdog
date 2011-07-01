/*****************************************************************************
* Filename : homewatchdog.h
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#ifndef _homewatchdog_h_
#define _homewatchdog_h_

/* Call the GPIO & LEDs by ID */
typedef enum {
    GPIO1=0,
    GPIO2,
    GPIO3,
    GPIO4,
    GPIO5,
    GPIO6,
    GPIO7,
    GPIO8,
    GPIO9,
    LED1,
    LED2,
    LED3,
    LED4,
    MAX_OUTPUTS
} GPIO_t;

boolean initializeIO(void);         /* Init */
void setOutput(GPIO_t, boolean);    /* Set the on/off state of individual ports */
boolean getOutput(GPIO_t);          /* Return the on/off state of requested port */
void allOutputOn(void);             /* Demo - Turn everything on */
void allOutputOff(void);            /* Demo - Turn everything off */
void allOutputToggle(void);         /* Demo - Toggle on/off for everything */

#endif
