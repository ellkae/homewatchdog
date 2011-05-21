/*****************************************************************************
* Filename : homewatchdog.h
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#ifndef _homewatchdog_h_
#define _homewatchdog_h_

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

static FILE_PTR output_port=NULL;

boolean initializeIO(void);
void setOutput(GPIO_t, boolean);
boolean getOutput(GPIO_t);
void allOutputOn(void);
void allOutputOff(void);
void allOutputToggle(void);

#endif