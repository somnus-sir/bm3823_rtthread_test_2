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
#include <rthw.h>
#include <rtthread.h>
#include "bm3823a.h"

static int tst_a = 0, tst_b = 0, tst_c = 0;

void rt_hw_context_switch_interrupt(rt_ubase_t from, rt_ubase_t to)
{
    rt_kprintf("rt_hw_context_switch_interrupt\n");
}

int main(int argc, char** argv)
{
    rt_kprintf("sparc v8 hello rt-thread!\n");

    rt_kprintf("test value: a %d addr: %p, b %d addr:%p, c %d addr:%p\n", tst_a, &tst_a, tst_b, &tst_b, tst_c, &tst_c);


	return 0;
}
