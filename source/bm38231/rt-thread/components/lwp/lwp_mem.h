/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-06-10     Bernard      first version
 */

#ifndef __LWP_MEM_H__
#define __LWP_MEM_H__

extern void rt_lwp_mem_init(struct rt_lwp *lwp);
extern void rt_lwp_mem_deinit(struct rt_lwp *lwp);

extern void *rt_lwp_mem_malloc(rt_uint32_t size);
extern void rt_lwp_mem_free(void *addr);
extern void *rt_lwp_mem_realloc(void *rmem, rt_size_t newsize);

#endif
