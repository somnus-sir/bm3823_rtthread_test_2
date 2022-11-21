/**************************************************************************
 *
 * Filename:
 *
 *   register_inits.h
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
 *   $Id: register_inits.h,v 1.2 2010/12/20 04:38:19 nettleto Exp $
 *
 **************************************************************************/

#ifndef _REGISTER_INITS_H_
#define _REGISTER_INITS_H_

/* Register initial values (writable fields only) */

/* Table 2. Processor State Register */

#define I_PSR_N            0x0        /* Negative */
#define I_PSR_Z            0x0        /* Zero */
#define I_PSR_V            0x0        /* oVerflow */
#define I_PSR_C            0x0        /* Carry */
#define I_PSR_EF           0x1        /* Enable Floating-point Unit */
#define I_PSR_PIL          0x0        /* Processor Interrupt Level */
#define I_PSR_S            0x1        /* Supervisor */
#define I_PSR_PS           0x1        /* Previous Supervisor */
#define I_PSR_ET           0x0        /* Enable Traps */
#define I_PSR_CWP          0x07       /* Current Window Pointer */

/* Table 3. Window Invalid Mask */

#define I_WIM_WINDOW       0x02       /* invalid windows */

/* Table 4. Trap Base Register */

#define I_TBR_TBA          0x00000    /* trap base address */

/* Table 5. Y Register */

#define I_Y_Y              0x0000000  /* The Y register */

/* Table 7. FPU Status Register */

#define I_FSR_RD           0x0        /* rounding direction */
#define I_FSR_TEM          0x1a       /* trap enable mask */
#define I_FSR_FTT          0x0        /* Floating-point Trap Type */
#define I_FSR_FCC          0x0        /* Floating-point Condition Code */
#define I_FSR_AEXC         0x00       /* Accumulated Exception */
#define I_FSR_CEXC         0x00       /* Current Exception */

/* Table 10. System Control Register */

#define I_SYSCTR_US        0xc        /* UARTs Scaler */
#define I_SYSCTR_UCS       0x1        /* UARTs Clock Supply */
#define I_SYSCTR_USB       0x0        /* UARTs Stop Bit */
#define I_SYSCTR_UP        0x0        /* UARTs Parity */
#define I_SYSCTR_UPE       0x0        /* UARTs Parity Enable */
#define I_SYSCTR_UBR       0x1        /* UARTs Clock Supply */
#define I_SYSCTR_DST       0x0        /* UARTs Baud Rate */
#define I_SYSCTR_DPE       0x0        /* DMA Parity Enable */
#define I_SYSCTR_DMAE      0x0        /* DMA Enable */
#define I_SYSCTR_IWDE      0x0        /* Internal Watchdog Enable */
#define I_SYSCTR_RHSYSHE   0x1        /* Reset or Halt when System Hardware Error */
#define I_SYSCTR_SYSHEMSK  0x0        /* System Hardware Error Mask */
#define I_SYSCTR_RHIUHE    0x1        /* Reset or Halt when IU Hardware Error */
#define I_SYSCTR_IUEMSK    0x1        /* IU Hardware Error Mask */
#define I_SYSCTR_RHIUEM    0x1        /* Reset or Halt when IU Error Mode */
#define I_SYSCTR_IUEMMSK   0x0        /* IU Error Mode Mask */
#define I_SYSCTR_WDCD      0x0        /* Watchdog Clock Supply */
#define I_SYSCTR_BP        0x1        /* Block Protection */
#define I_SYSCTR_BTO       0x1        /* Bus Timeout */
#define I_SYSCTR_SWR       0x1        /* Software Reset */
#define I_SYSCTR_PRD       0x1        /* Power-down */

/* Table 11. Software Reset */

#define I_SWRST_SWRST      0x0000000  /* Software Reset */

/* Table 12. Power Down */

#define I_PDOWN_PDOWN      0x0000000  /* Power Down */

/* Table 13. System Fault Status Register */

#define I_SYSFSR_AT        0x0        /* Access Type */
#define I_SYSFSR_ASFT      0x0        /* Asynchronous Fault Type */
#define I_SYSFSR_ASFV      0x0        /* Asynchronous Fault Valid */
#define I_SYSFSR_SRFT      0x0        /* Synchronous Fault Type */
#define I_SYSFSR_SRFV      0x0        /* Synchronous Fault Valid */

/* Table 15. Error and Reset Status Register */

#define I_ERRRSR_SYSAV     0x1        /* System Availabilty */
#define I_ERRRSR_SYSHE     0x0        /* System Hardware Error */
#define I_ERRRSR_PFUHE     0x0        /* FPU Hardware Error */
#define I_ERRRSR_IUHE      0x0        /* IU Hardware Error */
#define I_ERRRSR_IUEM      0x0        /* IU Error Mode */

/* Table 16. Test Control Register */

#define I_TESTCTR_EWE      0x0        /* Error Write Enable */
#define I_TESTCTR_IT       0x0        /* Interrupt Force Enable */
#define I_TESTCTR_PT       0x0        /* Parity test Mode */
#define I_TESTCTR_ET       0x0        /* EDAC Test Mode */
#define I_TESTCTR_CB       0x00       /* Checks Bits for Test Mode */

/* Table 17. Memory Configuration Register */

#define I_MCNFR_EEX        0x0        /* Enable Exchange Memory */
#define I_MCNFR_EEC        0x0        /* Exchange Memory EDAC Protected */
#define I_MCNFR_EPA        0x0        /* Exchange Memory Parity Protected */
#define I_MCNFR_ESIZ       0x0        /* Exchange Memory Size */
#define I_MCNFR_PSIZ       0x0        /* Boot PROM Size */
#define I_MCNFR_P8         0x0        /* PROM 8-bit wide */
#define I_MCNFR_PWR        0x0        /* PROM Write Function */
#define I_MCNFR_REC        0x1        /* RAM EDAC Protected */
#define I_MCNFR_RPA        0x1        /* RAM Parity Protected */
#define I_MCNFR_RSIZ       0x3        /* RAM Size */
#define I_MCNFR_RBR1       0x0        /* Redundant RAM Block-1 Replace */
#define I_MCNFR_RBS1       0x0        /* Redundant RAM Block-1 Selected */
#define I_MCNFR_RBR0       0x0        /* Redundant RAM Block-0 Replace */
#define I_MCNFR_RBS0       0x0        /* Redundant RAM Block-0 Selected */
#define I_MCNFR_RBCS       0x0        /* Number of RAM Block Chip Selects */

/* Table 18. I/O Configuration Register */

#define I_IOCNFR_PA3       0x0        /* I/O Area 3 Parity Protected */
#define I_IOCNFR_IO3       0x0        /* I/O Area 3 Enable */
#define I_IOCNFR_SIZ3      0x0        /* I/O Area 3 Size */
#define I_IOCNFR_PA2       0x0        /* I/O Area 2 Parity Protected */
#define I_IOCNFR_IO2       0x0        /* I/O Area 2 Enable */
#define I_IOCNFR_SIZ2      0x0        /* I/O Area 2 Size */
#define I_IOCNFR_PA1       0x1        /* I/O Area 1 Parity Protected */
#define I_IOCNFR_IO1       0x1        /* I/O Area 1 Enable */
#define I_IOCNFR_SIZ1      0xF        /* I/O Area 1 Size */
#define I_IOCNFR_PA0       0x1        /* I/O Area 0 Parity Protected */
#define I_IOCNFR_IO0       0x1        /* I/O Area 0 Enable */
#define I_IOCNFR_SIZ0      0xF        /* I/O Area 0 Size */

/* Table 19. Waitstate Configuration Register */

#define I_WSCNFR_IO3RW     0x2        /* I/O Area 3, nbr of Read/Write Waitstates */
#define I_WSCNFR_IO2RW     0x2        /* I/O Area 2, nbr of Read/Write Waitstates */
#define I_WSCNFR_IO1RW     0x2        /* I/O Area 1, nbr of Read/Write Waitstates */
#define I_WSCNFR_IO0RW     0x2        /* I/O Area 0, nbr of Read/Write Waitstates */
#define I_WSCNFR_EXRW      0x0        /* Exchange Memory, nbr of Read/Write Waitstates */
#define I_WSCNFR_PRW       0xf        /* PROM Boot, nbr of Write Waitstates */
#define I_WSCNFR_PRR       0x3        /* PROM Boot, nbr of Read Waitstates */
#define I_WSCNFR_RAW       0x2        /* RAM, nbr of Write Waitstates */
#define I_WSCNFR_RAR       0x2        /* RAM, nbr of Read Waitstates */

/* Table 20. Access Protection Segment 1 Base Register */

#define I_APS1BR_SE1       0x0        /* Supervisor Enable - Segment 1 */
#define I_APS1BR_UE1       0x0        /* User Enable - Segment 1 */
#define I_APS1BR_SEG1BASE  0x000000   /* Segment 1 - Base Address */

/* Table 21. Access Protection Segment 1 End Register */

#define I_APS1ER_SEG1END   0x000000   /* Segment 1 - END Address */

/* Table 22. Access Protection Segment 1 Base Register */

#define I_APS2BR_SE2       0x0        /* Supervisor Enable - Segment 2 */
#define I_APS2BR_UE2       0x0        /* User Enable - Segment 2 */
#define I_APS2BR_SEG2BASE  0x000000   /* Segment 2 - Base Address */

/* Table 23. Access Protection Segment 2 End Register */

#define I_APS2ER_SEG2END   0x000000   /* Segment 2 - END Address */

/* Table 24. Interrupt Shape Register */

#define I_INTSHR_POL       0x00       /* External interrupts Polarity */
#define I_INTSHR_ACK       0x0        /* Acknowledge on external interrupt */
#define I_INTSHR_EDGE      0x1f       /* External interrupts EDGE (or level) triggered */

/* Table 26. Interrupt Mask Register */

#define I_INTMKR_IM        0x3fff     /* Interrupt Mask */

/* Table 27. Interrupt Clear Register */

#define I_INTCLR_IC        0x0000     /* Interrupt Clear */

/* Table 28. Interrupt ForceRegister */

#define I_INTFCR_IC        0x0000     /* Interrupt Force */

/* Table 29. Watchdog Timer Register */

#define I_WDOGTR_WDR       0x00       /* WatchDog Reset Counter */
#define I_WDOGTR_WDS       0x00       /* WatchDog Scalar */
#define I_WDOGTR_WDC       0x0000     /* WatchDog Counter */

/* Table 30. Watchdog Trap Door Set */

#define I_WDOGST_ST        0x0000000  /* Watchdog Trap Door Set */

/* Table 31. Real-time Clock Timer <Counter> Register */

#define I_RTCCR_RTCC       0x0000000  /* Real-time Clock Timer Counter */

/* Table 32. Real-time Clock Timer <Scalar> Register */

#define I_RTCSR_RTCS       0x0000     /* Real-time Clock Timer Scaler */

/* Table 33. General-Purpose Timer <Counter> Register */

#define I_GPTCR_RTCC       0x0000000  /* General-Purpose Timer Counter */

/* Table 34. General-Purpose Timer <Scaler> Register */

#define I_GPTSR_RTCC       0x0000     /* General-Purpose Timer Scaler */

/* Table 35. Timer Control Register */

#define I_TIMCTR_RTCSL     0x0        /* Real-time Clock Scaler Load */
#define I_TIMCTR_RTCE      0x0        /* Real-time Clock Enabled */
#define I_TIMCTR_RTCCL     0x0        /* Real-time Clock Counter Load */
#define I_TIMCTR_RTCR      0x0        /* Real-time Clock Reload */
#define I_TIMCTR_BHLT      0x0        /* UART B Halt */
#define I_TIMCTR_AHLT      0x0        /* UART A Halt */
#define I_TIMCTR_PHLT      0x0        /* Peripherals Halt */
#define I_TIMCTR_GPTSL     0x0        /* General-purpose Timer Scaler Load */
#define I_TIMCTR_GPTE      0x0        /* General-purpose Timer Enabled */
#define I_TIMCTR_GPTCL     0x0        /* General-purpose Timer Counter Load */
#define I_TIMCTR_GPTR      0x0        /* General-purpose Timer Reload */

/* Table 36. GPI Configuration Register */

#define I_GPICNFR_R_F      0x00       /* Falling edge/Rising edge */
#define I_GPICNFR_I_O      0x00       /* Input/Output configuration */

/* Table 37. GPI Data Register */

#define I_GPIDATR_GPID     0x00       /* GPI Data */

/* Table 38. UART 'A' Rx and Tx Register */

#define I_UARTAR_RTDA      0x00       /* Received or Transmitted Data of UART A */

/* Table 39. UART 'B' Rx and Tx Register */

#define I_UARTBR_RTDB      0x00       /* Received or Transmitted Data of UART B */

/* Table 40. UART Status Register */

#define I_UARTSR_CUB       0x0        /* Clear Errors on UART B */
#define I_UARTSR_OEB       0x0        /* Overrun Error on receiver B */
#define I_UARTSR_PEB       0x0        /* Parity Error on reviever B */
#define I_UARTSR_EFB       0x0        /* Frame Error on receiver B */
#define I_UARTSR_THEB      0x0        /* Transmitter Holding Register Empty on UART B */
#define I_UARTSR_TSEB      0x0        /* Transmitter Send Register Empty on UART B */
#define I_UARTSR_DRB       0x0        /* Data Ready in UART B */
#define I_UARTSR_CUB       0x0        /* Clear Errors on UART A */
#define I_UARTSR_OEB       0x0        /* Overrun Error on receiver A */
#define I_UARTSR_PEB       0x0        /* Parity Error on reviever A */
#define I_UARTSR_EFB       0x0        /* Frame Error on receiver A */
#define I_UARTSR_THEB      0x0        /* Transmitter Holding Register Empty on UART A */
#define I_UARTSR_TSEB      0x0        /* Transmitter Send Register Empty on UART A */
#define I_UARTSR_DRB       0x0        /* Data Ready in UART A */


#endif /* not _REGISTER_INITS_H_ */

