/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-12     Bernard      The first version
 */

#ifndef SIGNAL_H__
#define SIGNAL_H__

#include <libc/libc_signal.h>

#define SIG_DFL ((_sig_func_ptr)0)  /* Default action */
#define SIG_IGN ((_sig_func_ptr)1)  /* Ignore action */
#define SIG_ERR ((_sig_func_ptr)-1) /* Error return */

#endif
