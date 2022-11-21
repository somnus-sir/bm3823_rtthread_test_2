/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2015-01-28     Bernard      first version
 */
#include <rtthread.h>

#ifdef RT_USING_HEAP
void *malloc(rt_size_t n)
{
    return rt_malloc(n);
}

void *realloc(void *rmem, rt_size_t newsize)
{
    return rt_realloc(rmem, newsize);
}

void *calloc(rt_size_t nelem, rt_size_t elsize)
{
    return rt_calloc(nelem, elsize);
}

void free(void *rmem)
{
    rt_free(rmem);
}
#endif
