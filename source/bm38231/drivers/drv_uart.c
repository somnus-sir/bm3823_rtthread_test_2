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

/*@{*/
#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>

#include "bm3823a.h"
#include "drv_uart.h"

extern struct lregs *regs;

struct rt_uart_sparc
{
    void *base;
    rt_uint32_t IRQ;
};

static rt_err_t sparc_uart_configure(struct rt_serial_device *serial, struct serial_configure *cfg)
{
    rt_uint32_t baut_rate = 115200;
    rt_uint8_t mode = 0x3;
    regs->uartscaler1 = ((((CPU_FREQ2*10) / (8 * baut_rate))-5)/10);
    regs->uartstatus1 = 0;
    regs->uartctrl1   = (mode | 0x4);

    *(unsigned int *)0x81000408 = 0xaa00; 
    return RT_EOK;
}

static rt_err_t sparc_uart_control(struct rt_serial_device *serial, int cmd, void *arg)
{
    return RT_EOK;

}

static int sparc_uart_putc(struct rt_serial_device *serial, char c)
{
    while(!(regs->uartstatus1 & TH_EMPTY));
    regs->uartdata1 = c; /* write char to Transmit Buffer Register */

    return 1;
}

static int sparc_uart_getc(struct rt_serial_device *serial)
{
    if((regs->uartstatus1 & DATA_RD))
    {
        return (unsigned char)(regs->uartdata1);
    }
    else
    {
        return -1;
    }
}

struct rt_serial_device serial;
/* UART interrupt handler */
void uart_irq_handler(int vector, void *param)
{
    rt_hw_serial_isr(&serial, RT_SERIAL_EVENT_RX_IND);
}

static const struct rt_uart_ops sparc_uart_ops =
{
    sparc_uart_configure,
    sparc_uart_control,
    sparc_uart_putc,
    sparc_uart_getc,
};

struct rt_uart_sparc uart_dev0 =
{
    (void *)0x81000000,
    3,
};

void rt_hw_uart_init(void)
{
    struct rt_uart_sparc *uart;
    struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;

    uart = &uart_dev0;

    serial.ops    = &sparc_uart_ops;
    serial.config = config;
    rt_hw_interrupt_install(uart->IRQ, uart_irq_handler, &serial, "UART");
    rt_hw_interrupt_umask(uart->IRQ);
    /* register UART device */
    rt_hw_serial_register(&serial,
                          "uart",
                          RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX,
                          uart);
}
/*@}*/
