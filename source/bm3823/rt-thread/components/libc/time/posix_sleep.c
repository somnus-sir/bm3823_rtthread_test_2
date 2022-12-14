/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 */
#include <stdlib.h>
#include <rtthread.h>

#include <unistd.h>

unsigned int sleep(unsigned int seconds)
{
    rt_tick_t delta_tick;

    delta_tick = rt_tick_get();
    rt_thread_delay(seconds * RT_TICK_PER_SECOND);
    delta_tick = rt_tick_get() - delta_tick;

    return seconds - delta_tick/RT_TICK_PER_SECOND;
}
