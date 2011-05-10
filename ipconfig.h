/*****************************************************************************
* Filename : ipconfig.h
* Author : T.J. Telan
* Date : 10 May 2011
*****************************************************************************/

#ifndef _ipconfig_h_
#define _ipconfig_h_

#ifndef ENET_IPADDR
    #define ENET_IPADDR  IPADDR(192,168,0,100)
#endif

#ifndef ENET_IPMASK
    #define ENET_IPMASK  IPADDR(255,255,255,0)
#endif

#ifndef ENET_IPGATEWAY
    #define ENET_IPGATEWAY  IPADDR(192,168,0,1)
#endif

#endif