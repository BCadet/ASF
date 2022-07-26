/**
* Copyright (c) 2015 Microchip Technology Inc and 2012 – 2013, Thingsquare, http://www.thingsquare.com/. All rights reserved. 
*  
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
* 
* 2. Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution.
* 
* 3. Neither the name of Atmel nor the name of Thingsquare nor the names of its contributors may be used to endorse or promote products derived 
* from this software without specific prior written permission.  
* 
* 4. This software may only be redistributed and used in connection with an 
* Atmel microcontroller or Atmel wireless product.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
* GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
* 
* 
* 
*/


#ifndef IP64_CONF_SUB_H
#define IP64_CONF_SUB_H

#include "ip64-eth-interface.h"
#define DISABLE_DHCP 0
#undef UIP_FALLBACK_INTERFACE
#define UIP_FALLBACK_INTERFACE            ip64_eth_interface
#define IP64_CONF_UIP_FALLBACK_INTERFACE  ip64_eth_interface
#define IP64_CONF_INPUT                   ip64_eth_interface_input
#define IP64_CONF_DHCP                    1
//#if (DISABLE_DHCP == 0)
//#define IP64_CONF_DHCP                    1
//#define IP64_CONF_STATIC                  0
//#else
//#define IP64_CONF_DHCP                    0
//#define IP64_CONF_STATIC                  1
//#define STATIC_IPADDR                     "10.10.1.2"
//#define STATIC_NETMASK                    "255.0.0.0"
//#define STATIC_DEFAULT_ROUTER             "10.10.1.2" // currently not being used
//#endif

#include "ksz8851snl-ip64-driver.h"

#define IP64_CONF_ETH_DRIVER              ksz8851snl_ip64_driver

#endif /* IP64_CONF_SUB_H */


