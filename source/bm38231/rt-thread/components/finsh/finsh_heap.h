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
#include <finsh.h>

#ifndef __FINSH_HEAP_H__
#define __FINSH_HEAP_H__

int finsh_heap_init(void);
void* finsh_heap_allocate(size_t size);
void  finsh_heap_free(void*ptr);

#endif
