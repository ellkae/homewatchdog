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



#endif
