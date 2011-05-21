/*****************************************************************************
* Filename : homewatchdog.c
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#include "includes.h"

boolean initializeIO(void){

/* Initialization for demo PWM */  
//    FILE_PTR uart3_ptr;
// 
//    uart3_ptr = (pointer)fopen("ittyd:", (pointer) (IO_SERIAL_XON_XOFF));
//    
//    if(uart3_ptr == NULL) {
//        printf("cannot open ittyd device \n");
//    }
//    else {
//        printf("device opened succesfully \n"); 
//        write(uart3_ptr,(pointer)"A",1);	// write 1 char to uart1 or uart2
//		write(uart3_ptr,(pointer)"\n",1);	// write 1 char to uart1 or uart2
//        fflush(stdout);
//    }

    /* GPIO array definition   */
    const uint_32 output_set[] = {
        GPIO1 | GPIO_PIN_STATUS_1,
        GPIO2 | GPIO_PIN_STATUS_1,
        GPIO3 | GPIO_PIN_STATUS_1,
        GPIO4 | GPIO_PIN_STATUS_1,
        GPIO5 | GPIO_PIN_STATUS_1,
        GPIO6 | GPIO_PIN_STATUS_1,
        GPIO7 | GPIO_PIN_STATUS_1,
        GPIO8 | GPIO_PIN_STATUS_1,
        GPIO9 | GPIO_PIN_STATUS_1,
      
        BSP_LED1 | GPIO_PIN_STATUS_0,
        BSP_LED2 | GPIO_PIN_STATUS_0,
        BSP_LED3 | GPIO_PIN_STATUS_0,
        BSP_LED4 | GPIO_PIN_STATUS_0,
        GPIO_LIST_END
    };
  
    // Set GPIO array as outputs
    output_port = fopen("gpio:write", (char_ptr) &output_set);
  
    // Test GPIO by turning on all ports
    if (output_port){
        ioctl(output_port, GPIO_IOCTL_WRITE_LOG1, &output_port);
    }
    
    return 0;
}

void allOutputOn(void){
    return;
}

void allOutputOff(void){
    return;
}

void allOutputToggle(void){
    return;
}