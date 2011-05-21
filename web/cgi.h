/*****************************************************************************
* Filename : cgi.h
* Author : T.J. Telan
* Date : 18 May 2011
*****************************************************************************/

#ifndef _cgi_h_
#define _cgi_h_

#include "homewatchdog.h"

int cgi_rtc_data(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio1(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio2(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio3(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio4(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio5(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio6(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio7(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio8(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_gpio9(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_led1(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_led2(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_led3(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_led4(HTTPD_SESSION_STRUCT *session);
int cgi_toggle_all(HTTPD_SESSION_STRUCT *session);
int cgi_allOn(HTTPD_SESSION_STRUCT *session);
int cgi_allOff(HTTPD_SESSION_STRUCT *session);

#define CGI_SEND_NUM(val)                   \
{                                           \
        char str[20], *pstr;                \
        pstr = &str[0];                     \
        sprintf(pstr, "%ld\n", val);        \
        httpd_sendstr(session->sock, str);  \
}

#endif
