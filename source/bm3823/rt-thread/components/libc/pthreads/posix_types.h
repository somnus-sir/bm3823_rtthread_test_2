/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2013-12-23     Bernard      Add the checking for ESHUTDOWN 
 */

#ifndef __POSIX_TYPES_H__
#define __POSIX_TYPES_H__

#include <rtthread.h>

#include <stddef.h>
#include <stdarg.h>
#include <string.h>

#include <sys/types.h>
#include <sys/time.h>

/* errno for Keil MDK */
#if defined(__CC_ARM) || defined(__IAR_SYSTEMS_ICC__)
#include <sys/errno.h>
#include <sys/unistd.h>
#else
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#endif

#endif

