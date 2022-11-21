/**************************************************************************
 *   
 * Filename:
 * 
 *   register_offsets.h 
 *   
 * Description:
 *
 *   Authority is "TSC695F, SPARC 32-Bit Space Processor User Manual"
 *   Ref 4148H-AERO-12/03, Temic Semiconductors
 *
 * Credits:
 *
 *   Copyright (c) 2010, XGC Technology (www.xgc.com)
 *
 * License:
 * 
 *   The authors hereby grant permission to use, copy, modify, distribute, 
 *   and license this software and its documentation for any purpose, 
 *   provided that existing copyright notices are retained in all copies
 *   and that this notice is included verbatim in any distributions.
 *
 * Revision:
 *
 *   $Id: register_offsets.h,v 1.1 2010/12/01 10:18:12 nettleto Exp $
 *
 **************************************************************************/

/* System register offsets from 0x01f80000 */

#define O_SYSCTR     0x000      /* System Control Register */
#define O_SWRST      0x004      /* Software Reset */
#define O_PDOWN      0x008      /* Power Down */
#define O_SYSFSR     0x0a0      /* System Fault Status Register */
#define O_FAILAR     0x0a4      /* Fail Address Register */
#define O_ERRRSR     0x0b0      /* Error and Reset Status Register */
#define O_TESTCTR    0x0d0      /* Test Control Register */
#define O_MCNFR      0x010      /* Memory Configuration Register */
#define O_IOCNFR     0x014      /* I/O Configuration Register */
#define O_WSCNFR     0x018      /* Waitstate Configuration Register */
#define O_APS1BR     0x020      /* Access Protection Segment 1 Base Register */
#define O_APS1ER     0x024      /* Access Protection Segment 1 End Register */
#define O_APS2BR     0x028      /* Access Protection Segment 1 Base Register */
#define O_APS2ER     0x02c      /* Access Protection Segment 2 End Register */
#define O_INTSHR     0x044      /* Interrupt Shape Register */
#define O_INTPDR     0x048      /* Interrupt Pending Register */
#define O_INTMKR     0x04c      /* Interrupt Mask Register */
#define O_INTCLR     0x050      /* Interrupt Clear Register */
#define O_INTFCR     0x054      /* Interrupt ForceRegister */
#define O_WDOGTR     0x060      /* Watchdog Timer Register */
#define O_WDOGST     0x064      /* Watchdog Trap Door Set */
#define O_RTCCR      0x080      /* Real-time Clock Timer <Counter> Register */
#define O_RTCSR      0x084      /* Real-time Clock Timer <Scalar> Register */
#define O_GPTCR      0x088      /* General-Purpose Timer <Counter> Register */
#define O_GPTSR      0x08c      /* General-Purpose Timer <Scaler> Register */
#define O_TIMCTR     0x098      /* Timer Control Register */
#define O_GPICNFR    0x0a8      /* GPI Configuration Register */
#define O_GPIDATR    0x0ac      /* GPI Data Register */
#define O_UARTAR     0x0e0      /* UART 'A' Rx and Tx Register */
#define O_UARTBR     0x0e4      /* UART 'B' Rx and Tx Register */
#define O_UARTSR     0x0e8      /* UART Status Register */

