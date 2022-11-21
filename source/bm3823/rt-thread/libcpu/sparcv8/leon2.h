/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-07     bigmagic     first version
 */

#ifndef LEON2_H__
#define LEON2_H__

#define SPARC_PSR_WIN_MASK  0x0000001f   /* bit   0-4 */
#define SPARC_PSR_ET_MASK   0x00000020   /* bit   5 */
#define SPARC_PSR_PS_MASK   0x00000040   /* bit   6 */
#define SPARC_PSR_S_MASK    0x00000080   /* bit   7 */
#define SPARC_PSR_PIL_MASK  0x00000F00   /* bits  8 - 11 */
#define SPARC_PSR_EF_MASK   0x00001000   /* bit  12 */
#define SPARC_PSR_EC_MASK   0x00002000   /* bit  13 */
#define SPARC_PSR_ICC_MASK  0x00F00000   /* bits 20 - 23 */
#define SPARC_PSR_VER_MASK  0x0F000000   /* bits 24 - 27 */
#define SPARC_PSR_IMPL_MASK 0xF0000000   /* bits 28 - 31 */
#define SPARC_PSR_PIL_SHIFT 8

#define RTTHREAD_STACK_SIZE (4*(8*2+4))
#define RTTHREAD_STACK_PSR_OFF (4*(8*2))
#define RTTHREAD_STACK_WIM_OFF (4*(8*2+1))
#define RTTHREAD_STACK_PC_OFF  (4*(8*2+2))
#define RTTHREAD_STACK_O0_OFF  (4*(8*2+3))


#define PT_REGS_SZ     0x50 /* 20*4 */
#define SF_REGS_SZ     0x60 /* 24*4 */
#define RW_REGS_SZ     0x20 /* 16*4 */
#define FW_REGS_SZ     0x90 /* 36*4 */

/* Reg_window offsets */
#define RW_L0     0x00
#define RW_L1     0x04
#define RW_L2     0x08
#define RW_L3     0x0c
#define RW_L4     0x10
#define RW_L5     0x14
#define RW_L6     0x18
#define RW_L7     0x1c
#define RW_I0     0x20
#define RW_I1     0x24
#define RW_I2     0x28
#define RW_I3     0x2c
#define RW_I4     0x30
#define RW_I5     0x34
#define RW_I6     0x38
#define RW_I7     0x3c

#endif
