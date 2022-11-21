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

#ifndef _DRV_UART_H__
#define _DRV_UART_H__

#include <rthw.h>
/*
 * the configuration of uart control register
 */
#define   REV_EN         0x1
#define   TRANS_EN       0x2
#define   REV_INT_EN     0x4
#define   TRANS_INT_EN   0x8
#define   PAR_SEL        0x10
#define   PAR_EN         0x20
#define   FLOW_CTR       0x40
#define   LOOP_BCK       0x80

/*
 * the configuration of uart status register
 */

#define   DATA_RD       0x1
#define   TS_EMPTY      0x2
#define   TH_EMPTY      0x4
#define   BREAK_REV     0x8
#define   OVERRUN       0x10
#define   PAR_ER        0x20
#define   FRAME_ER      0x40

void rt_hw_uart_init(void);

#endif
