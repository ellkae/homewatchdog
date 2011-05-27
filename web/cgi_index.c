/*****************************************************************************
* Filename : cgi_index.c
* Author : T.J. Telan
* Date : 19 May 2011
*****************************************************************************/

#include "ifconfig.h"

extern MQX_FILE_PTR output_port;

#if DEMOCFG_ENABLE_WEBSERVER
#include "cgi.h"

#include <string.h>
#include <stdlib.h>

extern LWSEM_STRUCT SD_Card;

static void sdcard_status_fn(HTTPD_SESSION_STRUCT *session);

const HTTPD_FN_LINK_STRUCT fn_lnk_tbl[] = {
    { "s_status_fn",  sdcard_status_fn },
    { 0, 0 } // DO NOT REMOVE - last item - end of table
};

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
    { 0, 0 }    // DO NOT REMOVE - last item - end of table
};


static void sdcard_status_fn(HTTPD_SESSION_STRUCT *session) {
#if BSPCFG_ENABLE_ESDHC
    if (SD_Card.VALUE)
        httpd_sendstr(session->sock, "visible");
    else
#endif
        httpd_sendstr(session->sock, "hidden");
}

// From Freescale
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

#endif
