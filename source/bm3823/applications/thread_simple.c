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
#include <rtthread.h>
#define THREAD_PRIORITY         25
#define THREAD_STACK_SIZE       2048
#define THREAD_TIMESLICE        5
static rt_thread_t tid2 = RT_NULL, tid1 = RT_NULL;

static void thread1_entry(void *parameter)
{
    rt_uint32_t count = 0;
    while (1)
    {
        rt_kprintf("thread1 count: %d\n", count ++);
        rt_thread_mdelay(500);
    }
}
ALIGN(RT_ALIGN_SIZE)
static char thread2_stack[1024];
static struct rt_thread thread2;

static void thread2_entry(void *param)
{
    rt_uint32_t count = 0;
    for (count = 0; count < 10 ; count++)
    {
        rt_kprintf("thread2 count: %d\n", count);
    }
    rt_kprintf("thread2 exit\n");
}

int thread_sample(void)
{
    tid1 = rt_thread_create("thread1",
                            thread1_entry, RT_NULL,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY, THREAD_TIMESLICE);
    if (tid1 != RT_NULL)
        rt_thread_startup(tid1);
     tid2 = rt_thread_create("thread2",
                            thread2_entry, RT_NULL,
                            THREAD_STACK_SIZE,
                            THREAD_PRIORITY - 1, THREAD_TIMESLICE);
    // rt_thread_init(&thread2,
    //                "thread2",
    //                thread2_entry,
    //                RT_NULL,
    //                &thread2_stack[0],
    //                sizeof(thread2_stack),
    //                THREAD_PRIORITY - 1, THREAD_TIMESLICE);
    rt_thread_startup(tid2);
    return 0;
}
MSH_CMD_EXPORT(thread_sample, thread sample);