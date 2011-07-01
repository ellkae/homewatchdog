/*****************************************************************************
* Filename : cgi_index.c
* Author : T.J. Telan
* Date : 19 May 2011
*****************************************************************************/

#include "includes.h"
#include "ifconfig.h"

extern MQX_FILE_PTR output_port;

#if DEMOCFG_ENABLE_WEBSERVER
#include "cgi.h"

#include <string.h>
#include <stdlib.h>

/* Link between C code and javascript 
 * Use:
 * { "javascript_fcn_name", C_cgi_fcn_name }
 * 
 * Note: You can pick the javascript name.
 * Check out javascript in webroot for examples */
const HTTPD_CGI_LINK_STRUCT cgi_lnk_tbl[] = {
    { "rtcdata",        cgi_rtc_data},
    { "togglegpio1",    cgi_toggle_gpio1},
    { "togglegpio2",    cgi_toggle_gpio2},
    { "togglegpio3",    cgi_toggle_gpio3},
    { "togglegpio4",    cgi_toggle_gpio4},
    { "togglegpio5",    cgi_toggle_gpio5},
    { "togglegpio6",    cgi_toggle_gpio6},
    { "togglegpio7",    cgi_toggle_gpio7},
    { "togglegpio8",    cgi_toggle_gpio8},
    { "togglegpio9",    cgi_toggle_gpio9},
    { "toggleled1",     cgi_toggle_led1},
    { "toggleled2",     cgi_toggle_led2},
    { "toggleled3",     cgi_toggle_led3},
    { "toggleled4",     cgi_toggle_led4},
    { "invert",         cgi_toggle_all},
    { "allon",          cgi_allOn},
    { "alloff",         cgi_allOff},

    /* Demo related */
    { "all_led_on",     cgi_all_led_on},
    { "all_led_off",    cgi_all_led_off},
    { "invert_led",     cgi_invert_led},

    { "all_light_on",   cgi_all_light_on},
    { "all_light_off",  cgi_all_light_off},
    { "invert_light",   cgi_invert_light},

    { "all_lock_on",    cgi_all_lock},
    { "all_lock_off",   cgi_all_unlock},


    { 0, 0 }    // DO NOT REMOVE - last item - end of table
};


/* From Freescale - 
 * Get system time, send to http client on request */
static int cgi_rtc_data(HTTPD_SESSION_STRUCT *session) {
    TIME_STRUCT time;
    DATE_STRUCT date;

    _time_get(&time);
    _time_to_date(&time,&date);

    CGI_SEND_NUM(date.HOUR);
    CGI_SEND_NUM(date.MINUTE);
    CGI_SEND_NUM(date.SECOND);

    return session->request.content_len;
}

/* Individual port control */

/* Status of port currently only reads to shell -
 * Easily would extend to web client with getOutput() */

/* Begin GPIO */
int cgi_toggle_gpio1(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio1 ");

    if(getOutput(GPIO1)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }

    setOutput(GPIO1,!getOutput(GPIO1));

    return session->request.content_len;
}

int cgi_toggle_gpio2(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio2 ");
    
    if(getOutput(GPIO2)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    setOutput(GPIO2,!getOutput(GPIO2));
    return session->request.content_len;
}

int cgi_toggle_gpio3(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio3 ");
    
    if(getOutput(GPIO3)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(GPIO3,!getOutput(GPIO3));
    return session->request.content_len;
}

int cgi_toggle_gpio4(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio4 ");
    
    if(getOutput(GPIO4)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(GPIO4,!getOutput(GPIO4));
    return session->request.content_len;
}

int cgi_toggle_gpio5(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio5 ");
    
    if(getOutput(GPIO5)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(GPIO5,!getOutput(GPIO5));
    return session->request.content_len;
}

int cgi_toggle_gpio6(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio6 ");
    
    if(getOutput(GPIO6)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(GPIO6,!getOutput(GPIO6));
    return session->request.content_len;
}

int cgi_toggle_gpio7(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio7 ");
    
    if(getOutput(GPIO7)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(GPIO7,!getOutput(GPIO7));
    return session->request.content_len;
}

int cgi_toggle_gpio8(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio8 ");
    
    if(getOutput(GPIO8)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(GPIO8,!getOutput(GPIO8));
    return session->request.content_len;
}

int cgi_toggle_gpio9(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle gpio9 ");
    
    if(getOutput(GPIO9)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(GPIO9,!getOutput(GPIO9));
    return session->request.content_len;
}

/* End GPIO */

/* Begin LEDs */

int cgi_toggle_led1(HTTPD_SESSION_STRUCT *session) {
    printf("DEBUG: Toggle led1 ");
    
    if(getOutput(LED1)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(LED1,!getOutput(LED1));
    return session->request.content_len;
}

int cgi_toggle_led2(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle led2 ");
    
    if(getOutput(LED2)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(LED2,!getOutput(LED2));
    return session->request.content_len;
}

int cgi_toggle_led3(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle led3 ");
    
    if(getOutput(LED3)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(LED3,!getOutput(LED3));
    return session->request.content_len;
}

int cgi_toggle_led4(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle led4 ");
    
    if(getOutput(LED4)){
        printf("OFF!\n");
    }
    else{
        printf("ON!\n");
    }
    
    setOutput(LED4,!getOutput(LED4));
    return session->request.content_len;
}

/* End LEDs*/

/* Power demo */
int cgi_toggle_all(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: Toggle all\n");
    allOutputToggle();
    return session->request.content_len;
}

int cgi_allOn(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: All ON\n");
    allOutputOn();
    return session->request.content_len;
}

int cgi_allOff(HTTPD_SESSION_STRUCT *session){
    printf("DEBUG: All OFF\n");
    allOutputOff();
    return session->request.content_len;
}

/* Demo board LEDs */
int cgi_all_led_on(HTTPD_SESSION_STRUCT *session){
    setOutput(LED1,ON);
    setOutput(LED2,ON);
    setOutput(LED3,ON);
    setOutput(LED4,ON);
    return session->request.content_len;
}

int cgi_all_led_off(HTTPD_SESSION_STRUCT *session){
    setOutput(LED1,OFF);
    setOutput(LED2,OFF);
    setOutput(LED3,OFF);
    setOutput(LED4,OFF);
    return session->request.content_len;
}

int cgi_invert_led(HTTPD_SESSION_STRUCT *session){

    // Quick and dirty version...
    int i;
    for(i=LED1; i < MAX_OUTPUTS; i++){
        if(getOutput((GPIO_t)i)){
            setOutput((GPIO_t)i,OFF);
        }
        else {
            setOutput((GPIO_t)i,ON);
        }
    }
    return session->request.content_len;
}

/* Light Demo */
int cgi_all_light_on(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO1,ON);
    setOutput(GPIO5,ON);
    setOutput(GPIO6,ON);
    return session->request.content_len;
}
int cgi_all_light_off(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO1,OFF);
    setOutput(GPIO5,OFF);
    setOutput(GPIO6,OFF);
    return session->request.content_len;
}

int cgi_invert_light(HTTPD_SESSION_STRUCT *session){
    // quick and dirty...
    if(getOutput(GPIO1)){
        setOutput(GPIO1,OFF);
    }
    else {
        setOutput(GPIO1,ON);
    }
    
    if(getOutput(GPIO5)){
        setOutput(GPIO5,OFF);
    }
    else {
        setOutput(GPIO5,ON);
    }
    
    if(getOutput(GPIO6)){
        setOutput(GPIO6,OFF);
    }
    else {
        setOutput(GPIO6,ON);
    }
    return session->request.content_len;
}

/* Security demo */
int cgi_all_lock(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO2,ON);
    setOutput(GPIO3,ON);
    return session->request.content_len;
}

int cgi_all_unlock(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO2,OFF);
    setOutput(GPIO3,OFF);
    return session->request.content_len;
}
#endif
