/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 * 
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-07     bigmagic     Initial version
 */

#ifndef BOARD_H__
#define BOARD_H__

#include <stdint.h>

extern unsigned char __bss_end;

#define RT_HW_HEAP_BEGIN    (void*)&__bss_end
#define RT_HW_HEAP_END      (void*)(RT_HW_HEAP_BEGIN + 64 * 1024 * 1024)

void rt_hw_board_init(void);
void rt_hw_timer_handler(int vector, void* param);

#endif
