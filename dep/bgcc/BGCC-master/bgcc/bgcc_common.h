/***********************************************************************
  * Copyright (c) 2013, Baidu Inc. All rights reserved.
  * 
  * Licensed under the BSD License
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *      license.txt
  *********************************************************************/

#ifndef  __BGCC_COMMON_H_
#define  __BGCC_COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <time.h>
typedef int int32_t;
typedef int ssize_t;
typedef int socklen_t;

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000Ui64
#else
#define DELTA_EPOCH_IN_MICROSECS  11644473600000000ULL
#endif
#if _MSC_VER < 1600
typedef __int8				int8_t;
typedef __int16				int16_t;
typedef __int32				int32_t;
typedef __int64				int64_t;

typedef unsigned __int8		uint8_t;
typedef unsigned __int16	uint16_t;
typedef unsigned __int32	uint32_t;
typedef unsigned __int64	uint64_t;

#pragma warning( disable : 4065 4267 )
#else
#pragma warning( disable : 4996 )
#include <stdint.h>
#endif
#else
#include <unistd.h>
#include <stdint.h>
#include <signal.h>
#include <errno.h>
#include <sys/time.h>
#include <linux/unistd.h>

#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <pthread.h>
#include <semaphore.h>

#endif


#ifndef _WIN32
#define SOCKET int32_t
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define MAXNFD 10000
#else
#define snprintf _snprintf
#endif

#ifndef TRANSPORTID
#define TRANSPORTID	SOCKET
#endif


#define DEFAULT_HB_TIMEOUT	1000
#define DEFAULT_SERVER_TIMEOUT	5000
#define THREADPOOL_GET_TASK_TIMEOUT	1000
#define DEFAULT_CLIENT_TIMEOUT  120000

#define bswap_64(x) ((uint64_t)( \
            (((uint64_t)(x) & (uint64_t)0x00000000000000ffull) << 56) | \
            (((uint64_t)(x) & (uint64_t)0x000000000000ff00ull) << 40) | \
            (((uint64_t)(x) & (uint64_t)0x0000000000ff0000ull) << 24) | \
            (((uint64_t)(x) & (uint64_t)0x00000000ff000000ull) << 8)  | \
            (((uint64_t)(x) & (uint64_t)0x000000ff00000000ull) >> 8)  | \
            (((uint64_t)(x) & (uint64_t)0x0000ff0000000000ull) >> 24) | \
            (((uint64_t)(x) & (uint64_t)0x00ff000000000000ull) >> 40) | \
            (((uint64_t)(x) & (uint64_t)0xff00000000000000ull) >> 56)))

#ifdef _BIG_ENDIAN
#define htonll(x) (x)
#define ntohll(x) (x)
#else
#define htonll(x) bswap_64(x)
#define ntohll(x) bswap_64(x)
#endif

#ifdef __GNUC__
#define DEPRECATED(func) func __attribute__ ((deprecated))
#define DEPRECATED_CLASS(NewClass, OldClass) typedef NewClass __attribute__((deprecated)) OldClass;
#elif defined(_MSC_VER)
#define DEPRECATED(func) __declspec(deprecated) func
#define DEPRECATED_CLASS(NewClass, OldClass) typedef NewClass __declspec(deprecated) OldClass;
#else
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define DEPRECATED(func) func
#endif

#endif  //__COMMON_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
