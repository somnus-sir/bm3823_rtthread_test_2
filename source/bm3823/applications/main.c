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

static int tst_a = 5, tst_b = 2,tst_c;

void rt_hw_context_switch_interrupt(rt_ubase_t from, rt_ubase_t to)
{
    rt_kprintf("rt_hw_context_switch_interrupt\n");
}

int test_add(int a, int b)
{
    int c = 0;

    c = a+b;

    return c;
 }

int test_mul(int a, int b)
{
    int c = 0;

    c = a*b;

    return c;
 }

int main(int argc, char** argv)
{
    int a;
    for( a = 10; a < 30; a=a+1) {


    tst_c=test_add(tst_a, tst_b);

    rt_kprintf("test value: a %d addr: %p, b %d addr:%p, c %d addr:%p\n", tst_a, &tst_a, tst_b, &tst_b, tst_c, &tst_c);

//    tst_f=test_mul(tst_d, tst_e);

    rt_kprintf("sparc v8 hello rt-thread!\n");

//    rt_kprintf("test value: a %d addr: %p, b %d addr:%p, c %d addr:%p\n", tst_d, &tst_d, tst_e, &tst_e, tst_f, &tst_f);

//    rt_kprintf("test value: a %d addr: %p, b %d addr:%p, c %d addr:%p\n", tst_a, &tst_a, tst_b, &tst_b, tst_c, &tst_c);
    }
	return 0;
}








