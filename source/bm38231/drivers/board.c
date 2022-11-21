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
#include <rthw.h>

#include "drv_uart.h"
#include "board.h"
#include "bm3823a.h"

struct lregs *regs = (struct lregs *)0x81000000;

/**
 * This is the timer interrupt service routine.
 */
void rt_hw_timer_handler(int vector, void* param)
{
    /* increase a OS tick */
    rt_tick_increase();
}

/**
 * This function will initial OS timer
 */
void rt_hw_timer_init(void)
{
    regs->scalerload = BUS_2_FREQ/1000000 -1;
    regs->scalercnt  = BUS_2_FREQ/1000000 -1;

    regs->timercnt1  = 1000 * (1000 / RT_TICK_PER_SECOND) - 1;
    regs->timerload1 = 1000 * (1000 / RT_TICK_PER_SECOND) - 1;

    regs->timerctrl1 = 0;

    regs->timerctrl1 = RELOAD_COUNT |LOAD_COUNT|COUNT_EN;
    rt_hw_interrupt_install(14, rt_hw_timer_handler, 0, "timer");
    rt_hw_interrupt_umask(14);
}
/**
 * Board level initialization
 */
void rt_hw_board_init(void)
{
    //rt_hw_exception_init();
    /* init hardware interrupt */
    rt_hw_interrupt_init();

#ifdef RT_USING_SERIAL
    /* init hardware UART device */
    rt_hw_uart_init();
    /* set console device */
    rt_console_set_device("uart");
#endif
    
#ifdef RT_USING_HEAP
    rt_system_heap_init((void*)RT_HW_HEAP_BEGIN, (void*)RT_HW_HEAP_END);
#endif

    /* init operating system timer */
    rt_hw_timer_init();

#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
   
}
