/*****************************************************************************
* Filename : start_task.c
* Author : T.J. Telan
* Date : 6 May 2011
*****************************************************************************/

/*----------------------------------------------------------------------------
- Task Name : start_task
- Comments :
----------------------------------------------------------------------------*/

void start_task(uint_32 initial_data){
   printf("Hello World\n"); 
   
    FILE_PTR output_port;

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
  
  
  if (output_port){
        printf("Turn ons?\n");
        ioctl(output_port, GPIO_IOCTL_WRITE_LOG1, &output_port);

  }
   /* 
   ** This example uses polled serial I/O by default. Should it be modified
   ** to use interrupt driven serial drivers, you will need to uncomment the
   ** following delay code to insure serial communication completes before 
   ** _mqx_exit() disables all interrupts.
   */
  _time_delay(200);
   
   _mqx_exit(0);

}

/* EOF */