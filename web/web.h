#include <mqx.h>
#include <bsp.h>
#include <rtcs.h>
#include "httpd.h"

#define DEMOCFG_ENABLE_RTCS            1   /* enable RTCS operation */
#define DEMOCFG_ENABLE_WEBSERVER       1   /* enable web server */
#define DEMOCFG_ENABLE_DHCP            0   /* enable DHCP Client */

extern void initialize_networking(void);
#ifndef ENET_IPADDR
    #define ENET_IPADDR  IPADDR(169,254,3,3)
 #endif

 #ifndef ENET_IPMASK
    #define ENET_IPMASK  IPADDR(255,255,255,0)
 #endif

 #ifndef ENET_IPGATEWAY
    #define ENET_IPGATEWAY  IPADDR(192,168,1,1)
 #endif

#ifndef DEMOCFG_DEFAULT_DEVICE
   #define DEMOCFG_DEFAULT_DEVICE   BSP_DEFAULT_ENET_DEVICE
#endif
