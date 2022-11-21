/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2013-06-15     Bernard      the first verion
 */
#include <rthw.h>
#include <rtthread.h>
#include <interrupt.h>
#include "vmm.h"

void vmm_guest_isr(int irqno, void* parameter)
{
    /* nothing, let GuestOS to handle it */
    rt_hw_interrupt_clear(irqno);
}

void vmm_vector_init(void)
{
	rt_hw_interrupt_install(RT_VMM_VIRQ_TRIGGER, vmm_guest_isr, RT_NULL, "virq");
	rt_hw_interrupt_umask(RT_VMM_VIRQ_TRIGGER);

	return;
}

