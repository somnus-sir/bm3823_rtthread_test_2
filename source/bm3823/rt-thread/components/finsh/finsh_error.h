/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-03-22     Bernard      first version
 */
#ifndef __FINSH_ERROR_H__
#define __FINSH_ERROR_H__

#include <finsh.h>

int finsh_error_init(void);

/* get error number */
uint8_t finsh_errno(void);

int finsh_error_set(uint8_t type);
const char* finsh_error_string(uint8_t type);

#endif
