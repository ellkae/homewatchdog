/*****************************************************************************
* Filename : homewatchdog.c
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

#include "includes.h"

boolean output_state[MAX_OUTPUTS];

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
        USR_GPIO1 | GPIO_PIN_STATUS_1,
        USR_GPIO2 | GPIO_PIN_STATUS_1,
        USR_GPIO3 | GPIO_PIN_STATUS_1,
        USR_GPIO4 | GPIO_PIN_STATUS_1,
        USR_GPIO5 | GPIO_PIN_STATUS_1,
        USR_GPIO6 | GPIO_PIN_STATUS_1,
        USR_GPIO7 | GPIO_PIN_STATUS_1,
        USR_GPIO8 | GPIO_PIN_STATUS_1,
        USR_GPIO9 | GPIO_PIN_STATUS_1,
      
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
    
    return (output_port!=NULL);
}

void setOutput(GPIO_t signal, boolean state){
    //Set up GPIO structure for each LED + GPIO port
    static const uint_32 gpio1[] = {
        USR_GPIO1,
        GPIO_LIST_END
    };
    static const uint_32 gpio2[] = {
        USR_GPIO2,
        GPIO_LIST_END
    };
    static const uint_32 gpio3[] = {
        USR_GPIO3,
        GPIO_LIST_END
    };
    static const uint_32 gpio4[] = {
        USR_GPIO4,
        GPIO_LIST_END
    };
    static const uint_32 gpio5[] = {
        USR_GPIO5,
        GPIO_LIST_END
    };
    static const uint_32 gpio6[] = {
        USR_GPIO6,
        GPIO_LIST_END
    };
    static const uint_32 gpio7[] = {
        USR_GPIO7,
        GPIO_LIST_END
    };
    static const uint_32 gpio8[] = {
        USR_GPIO8,
        GPIO_LIST_END
    };
    static const uint_32 gpio9[] = {
        USR_GPIO9,
        GPIO_LIST_END
    };    
    static const uint_32 led1[] = {
        BSP_LED1,
        GPIO_LIST_END
    };
    static const uint_32 led2[] = {
        BSP_LED2,
        GPIO_LIST_END
    };
    static const uint_32 led3[] = {
        BSP_LED3,
        GPIO_LIST_END
    };
    static const uint_32 led4[] = {
        BSP_LED4,
        GPIO_LIST_END
    };  
    //If the output device driver was successfully opened...
    if (output_port) {
        //Store state in variable
        output_state[signal] = state;

        //Set LED on or off based on the state passed to function
        switch (signal) {
        case GPIO1:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio1);
            break;
        case GPIO2:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio2);
            break;
        case GPIO3:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio3);
            break;
        case GPIO4:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio4);
            break;
        case GPIO5:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio5);
            break;
        case GPIO6:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio6);
            break;
        case GPIO7:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio7);
            break;
        case GPIO8:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio8);
            break;
        case GPIO9:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &gpio9);
            break;
        case LED1:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &led1);
            break;
        case LED2:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &led2);
            break;
        case LED3:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &led3);
            break;
        case LED4:
            ioctl(output_port, (state) ? GPIO_IOCTL_WRITE_LOG0 : GPIO_IOCTL_WRITE_LOG1, (pointer) &led4);
            break;
        }       
    }
    return;  
}

boolean getOutput(GPIO_t signal){
    if(signal<MAX_OUTPUTS) {
        return output_state[signal];
    }
    else {
        return FALSE;
    }
}


void allOutputOn(void){
    setOutput(GPIO1,ON);
    setOutput(GPIO2,ON);
    setOutput(GPIO3,ON);
    setOutput(GPIO4,ON);
    setOutput(GPIO5,ON);
    setOutput(GPIO6,ON);
    setOutput(GPIO7,ON);
    setOutput(GPIO8,ON);
    setOutput(GPIO9,ON);
    setOutput(LED1,ON);
    setOutput(LED2,ON);
    setOutput(LED3,ON);
    setOutput(LED4,ON);
    return;
}

void allOutputOff(void){
    setOutput(GPIO1,OFF);
    setOutput(GPIO2,OFF);
    setOutput(GPIO3,OFF);
    setOutput(GPIO4,OFF);
    setOutput(GPIO5,OFF);
    setOutput(GPIO6,OFF);
    setOutput(GPIO7,OFF);
    setOutput(GPIO8,OFF);
    setOutput(GPIO9,OFF);
    setOutput(LED1,OFF);
    setOutput(LED2,OFF);
    setOutput(LED3,OFF);
    setOutput(LED4,OFF);
    return;
}

void allOutputToggle(void){
    int i;
    for(i=0; i < MAX_OUTPUTS; i++){
        if(getOutput((GPIO_t)i)){
            setOutput((GPIO_t)i,OFF);
        }
        else {
            setOutput((GPIO_t)i,ON);
        }
    }
    return;
}