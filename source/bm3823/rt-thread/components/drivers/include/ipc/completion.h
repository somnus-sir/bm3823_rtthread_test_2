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
#ifndef COMPLETION_H_
#define COMPLETION_H_

#include <rtthread.h>

/**
 * Completion
 */

struct rt_completion
{
    rt_uint32_t flag;

    /* suspended list */
    rt_list_t suspended_list;
};

void rt_completion_init(struct rt_completion *completion);
rt_err_t rt_completion_wait(struct rt_completion *completion,
                            rt_int32_t            timeout);
void rt_completion_done(struct rt_completion *completion);

#endif
