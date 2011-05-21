/*****************************************************************************
* Filename : cgi_index.c
* Author : T.J. Telan
* Date : 19 May 2011
*****************************************************************************/

#include "ipconfig.h"

extern MQX_FILE_PTR output_port;

#if DEMOCFG_ENABLE_WEBSERVER
#include "html.h"
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
    setOutput(GPIO1,!getOutput(GPIO1));
    return session->request.content_len;
}

int cgi_toggle_gpio2(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO2,!getOutput(GPIO2));
    return session->request.content_len;
}

int cgi_toggle_gpio3(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO3,!getOutput(GPIO3));
    return session->request.content_len;
}

int cgi_toggle_gpio4(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO4,!getOutput(GPIO4));
    return session->request.content_len;
}

int cgi_toggle_gpio5(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO5,!getOutput(GPIO5));
    return session->request.content_len;
}

int cgi_toggle_gpio6(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO6,!getOutput(GPIO6));
    return session->request.content_len;
}

int cgi_toggle_gpio7(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO7,!getOutput(GPIO7));
    return session->request.content_len;
}

int cgi_toggle_gpio8(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO8,!getOutput(GPIO8));
    return session->request.content_len;
}

int cgi_toggle_gpio9(HTTPD_SESSION_STRUCT *session){
    setOutput(GPIO9,!getOutput(GPIO9));
    return session->request.content_len;
}


int cgi_toggle_led1(HTTPD_SESSION_STRUCT *session) {
    setOutput(LED1,!getOutput(LED1));
    return session->request.content_len;
}

int cgi_toggle_led2(HTTPD_SESSION_STRUCT *session){
    setOutput(LED2,!getOutput(LED2));
    return session->request.content_len;
}

int cgi_toggle_led3(HTTPD_SESSION_STRUCT *session){
    setOutput(LED3,!getOutput(LED3));
    return session->request.content_len;
}

int cgi_toggle_led4(HTTPD_SESSION_STRUCT *session){
    setOutput(LED4,!getOutput(LED4));
    return session->request.content_len;
}

int cgi_toggle_all(HTTPD_SESSION_STRUCT *session){
    allOutputToggle();
    return session->request.content_len;
}

int cgi_allOn(HTTPD_SESSION_STRUCT *session){
    allOutputOn();
    return session->request.content_len;
}

int cgi_allOff(HTTPD_SESSION_STRUCT *session){
    allOutputOff();
    return session->request.content_len;
}

#endif
