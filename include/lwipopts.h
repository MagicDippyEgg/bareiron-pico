#ifndef _LWIPOPTS_H
#define _LWIPOPTS_H

#ifndef NO_SYS
#define NO_SYS 1
#endif

// Disable socket and netconn APIs when using lwIP in NO_SYS=1 (bare-metal) mode
#ifndef LWIP_SOCKET
#define LWIP_SOCKET 0
#endif

#ifndef LWIP_NETCONN
#define LWIP_NETCONN 0
#endif

#ifndef LWIP_TIMEVAL_PRIVATE
#define LWIP_TIMEVAL_PRIVATE 0
#endif

#ifndef LWIP_TCPIP_CORE_LOCKING
#define LWIP_TCPIP_CORE_LOCKING 0
#endif

// Memory and tuning for Pico W
#define MEM_LIBC_MALLOC 0
#define MEM_ALIGNMENT 4
#define MEM_SIZE (32 * 1024)

#define MEMP_NUM_TCP_PCB 16
#define MEMP_NUM_TCP_PCB_LISTEN 8
#define MEMP_NUM_TCP_SEG 64
#define MEMP_NUM_SYS_TIMEOUT 16

#define TCP_MSS 1460
#define TCP_WND (8 * TCP_MSS)
#define TCP_SND_BUF (8 * TCP_MSS)

#define LWIP_DHCP 1
#define LWIP_DNS 1
#define LWIP_UDP 1
#define LWIP_TCP 1

#endif
