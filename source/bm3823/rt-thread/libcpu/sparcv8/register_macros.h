/**************************************************************************
 *
 * Filename:
 *
 *   register_macros.h
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
 *   $Id: register_macros.h,v 1.2 2010/12/20 04:38:19 nettleto Exp $
 *
 **************************************************************************/

#ifndef _REGISTER_MACROS_H_
#define _REGISTER_MACROS_H_

/* Table 2. Processor State Register */

#define I_PSR (\
  ((I_PSR_N << 23) & 0x00800000) | \
  ((I_PSR_Z << 22) & 0x00400000) | \
  ((I_PSR_V << 21) & 0x00200000) | \
  ((I_PSR_C << 20) & 0x00100000) | \
  ((I_PSR_EF << 12) & 0x00001000) | \
  ((I_PSR_PIL << 8) & 0x00000f00) | \
  ((I_PSR_S << 7) & 0x00000080) | \
  ((I_PSR_PS << 6) & 0x00000040) | \
  ((I_PSR_ET << 5) & 0x00000020) | \
  ((I_PSR_CWP << 0) & 0x0000001f))

/* Table 3. Window Invalid Mask */

#define I_WIM (\
  ((I_WIM_WINDOW << 0) & 0x000000ff))

/* Table 4. Trap Base Register */

#define I_TBR (\
  ((I_TBR_TBA << 12) & 0xfffff000))

/* Table 5. Y Register */

#define I_Y (\
  ((I_Y_Y << 0) & 0xffffffff))

/* Table 7. FPU Status Register */

#define I_FSR (\
  ((I_FSR_RD << 30) & 0xc0000000) | \
  ((I_FSR_TEM << 23) & 0x0f800000) | \
  ((I_FSR_FTT << 14) & 0x0001c000) | \
  ((I_FSR_FCC << 10) & 0x00000c00) | \
  ((I_FSR_AEXC << 5) & 0x000003e0) | \
  ((I_FSR_CEXC << 0) & 0x0000001f))

/* Table 10. System Control Register */

#define I_SYSCTR (\
  ((I_SYSCTR_US << 24) & 0xff000000) | \
  ((I_SYSCTR_UCS << 23) & 0x00800000) | \
  ((I_SYSCTR_USB << 22) & 0x00400000) | \
  ((I_SYSCTR_UP << 21) & 0x00200000) | \
  ((I_SYSCTR_UPE << 20) & 0x00100000) | \
  ((I_SYSCTR_UBR << 19) & 0x00080000) | \
  ((I_SYSCTR_DST << 18) & 0x00040000) | \
  ((I_SYSCTR_DPE << 17) & 0x00020000) | \
  ((I_SYSCTR_DMAE << 16) & 0x00010000) | \
  ((I_SYSCTR_IWDE << 15) & 0x00008000) | \
  ((I_SYSCTR_RHSYSHE << 14) & 0x00004000) | \
  ((I_SYSCTR_SYSHEMSK << 13) & 0x00002000) | \
  ((I_SYSCTR_RHIUHE << 8) & 0x00000100) | \
  ((I_SYSCTR_IUEMSK << 7) & 0x00000080) | \
  ((I_SYSCTR_RHIUEM << 6) & 0x00000040) | \
  ((I_SYSCTR_IUEMMSK << 5) & 0x00000020) | \
  ((I_SYSCTR_WDCD << 4) & 0x00000010) | \
  ((I_SYSCTR_BP << 3) & 0x00000008) | \
  ((I_SYSCTR_BTO << 2) & 0x00000004) | \
  ((I_SYSCTR_SWR << 1) & 0x00000002) | \
  ((I_SYSCTR_PRD << 0) & 0x00000001))

/* Table 11. Software Reset */

#define I_SWRST (\
  ((I_SWRST_SWRST << 0) & 0xffffffff))

/* Table 12. Power Down */

#define I_PDOWN (\
  ((I_PDOWN_PDOWN << 0) & 0xffffffff))

/* Table 13. System Fault Status Register */

#define I_SYSFSR (\
  ((I_SYSFSR_AT << 12) & 0x0000f000) | \
  ((I_SYSFSR_ASFT << 9) & 0x00000600) | \
  ((I_SYSFSR_ASFV << 8) & 0x00000100) | \
  ((I_SYSFSR_SRFT << 3) & 0x00000078) | \
  ((I_SYSFSR_SRFV << 2) & 0x00000004))

/* Table 15. Error and Reset Status Register */

#define I_ERRRSR (\
  ((I_ERRRSR_SYSAV << 12) & 0x00001000) | \
  ((I_ERRRSR_SYSHE << 5) & 0x00000020) | \
  ((I_ERRRSR_PFUHE << 3) & 0x00000008) | \
  ((I_ERRRSR_IUHE << 1) & 0x00000002) | \
  ((I_ERRRSR_IUEM << 0) & 0x00000001))

/* Table 16. Test Control Register */

#define I_TESTCTR (\
  ((I_TESTCTR_EWE << 20) & 0x00100000) | \
  ((I_TESTCTR_IT << 19) & 0x00080000) | \
  ((I_TESTCTR_PT << 18) & 0x00040000) | \
  ((I_TESTCTR_ET << 17) & 0x00020000) | \
  ((I_TESTCTR_CB << 0) & 0x0000007f))

/* Table 17. Memory Configuration Register */

#define I_MCNFR (\
  ((I_MCNFR_EEX << 29) & 0x20000000) | \
  ((I_MCNFR_EEC << 28) & 0x10000000) | \
  ((I_MCNFR_EPA << 27) & 0x08000000) | \
  ((I_MCNFR_ESIZ << 24) & 0x07000000) | \
  ((I_MCNFR_PSIZ << 18) & 0x001c0000) | \
  ((I_MCNFR_P8 << 17) & 0x00020000) | \
  ((I_MCNFR_PWR << 16) & 0x00010000) | \
  ((I_MCNFR_REC << 14) & 0x00004000) | \
  ((I_MCNFR_RPA << 13) & 0x00002000) | \
  ((I_MCNFR_RSIZ << 10) & 0x00001c00) | \
  ((I_MCNFR_RBR1 << 7) & 0x00000380) | \
  ((I_MCNFR_RBS1 << 6) & 0x00000040) | \
  ((I_MCNFR_RBR0 << 3) & 0x00000038) | \
  ((I_MCNFR_RBS0 << 2) & 0x00000004) | \
  ((I_MCNFR_RBCS << 0) & 0x00000003))

/* Table 18. I/O Configuration Register */

#define I_IOCNFR (\
  ((I_IOCNFR_PA3 << 29) & 0x20000000) | \
  ((I_IOCNFR_IO3 << 28) & 0x10000000) | \
  ((I_IOCNFR_SIZ3 << 24) & 0x0f000000) | \
  ((I_IOCNFR_PA2 << 21) & 0x00200000) | \
  ((I_IOCNFR_IO2 << 20) & 0x00100000) | \
  ((I_IOCNFR_SIZ2 << 16) & 0x000f0000) | \
  ((I_IOCNFR_PA1 << 13) & 0x00002000) | \
  ((I_IOCNFR_IO1 << 12) & 0x00001000) | \
  ((I_IOCNFR_SIZ1 << 8) & 0x00000f00) | \
  ((I_IOCNFR_PA0 << 5) & 0x00000020) | \
  ((I_IOCNFR_IO0 << 4) & 0x00000010) | \
  ((I_IOCNFR_SIZ0 << 0) & 0x0000000f))

/* Table 19. Waitstate Configuration Register */

#define I_WSCNFR (\
  ((I_WSCNFR_IO3RW << 28) & 0xf0000000) | \
  ((I_WSCNFR_IO2RW << 24) & 0x0f000000) | \
  ((I_WSCNFR_IO1RW << 20) & 0x00f00000) | \
  ((I_WSCNFR_IO0RW << 16) & 0x000f0000) | \
  ((I_WSCNFR_EXRW << 12) & 0x0000f000) | \
  ((I_WSCNFR_PRW << 8) & 0x00000f00) | \
  ((I_WSCNFR_PRR << 4) & 0x000000f0) | \
  ((I_WSCNFR_RAW << 2) & 0x0000000c) | \
  ((I_WSCNFR_RAR << 0) & 0x00000003))

/* Table 20. Access Protection Segment 1 Base Register */

#define I_APS1BR (\
  ((I_APS1BR_SE1 << 24) & 0x01000000) | \
  ((I_APS1BR_UE1 << 23) & 0x00800000) | \
  ((I_APS1BR_SEG1BASE << 0) & 0x007fffff))

/* Table 21. Access Protection Segment 1 End Register */

#define I_APS1ER (\
  ((I_APS1ER_SEG1END << 0) & 0x007fffff))

/* Table 22. Access Protection Segment 1 Base Register */

#define I_APS2BR (\
  ((I_APS2BR_SE2 << 24) & 0x01000000) | \
  ((I_APS2BR_UE2 << 23) & 0x00800000) | \
  ((I_APS2BR_SEG2BASE << 0) & 0x007fffff))

/* Table 23. Access Protection Segment 2 End Register */

#define I_APS2ER (\
  ((I_APS2ER_SEG2END << 0) & 0x007fffff))

/* Table 24. Interrupt Shape Register */

#define I_INTSHR (\
  ((I_INTSHR_POL << 8) & 0x00001f00) | \
  ((I_INTSHR_ACK << 5) & 0x000000e0) | \
  ((I_INTSHR_EDGE << 0) & 0x0000001f))

/* Table 26. Interrupt Mask Register */

#define I_INTMKR (\
  ((I_INTMKR_IM << 1) & 0x00007ffe))

/* Table 27. Interrupt Clear Register */

#define I_INTCLR (\
  ((I_INTCLR_IC << 0) & 0x0000ffff))

/* Table 28. Interrupt ForceRegister */

#define I_INTFCR (\
  ((I_INTFCR_IC << 0) & 0x0000ffff))

/* Table 29. Watchdog Timer Register */

#define I_WDOGTR (\
  ((I_WDOGTR_WDR << 24) & 0xff000000) | \
  ((I_WDOGTR_WDS << 16) & 0x00ff0000) | \
  ((I_WDOGTR_WDC << 0) & 0x0000ffff))

/* Table 30. Watchdog Trap Door Set */

#define I_WDOGST (\
  ((I_WDOGST_ST << 0) & 0xffffffff))

/* Table 31. Real-time Clock Timer <Counter> Register */

#define I_RTCCR (\
  ((I_RTCCR_RTCC << 0) & 0xffffffff))

/* Table 32. Real-time Clock Timer <Scalar> Register */

#define I_RTCSR (\
  ((I_RTCSR_RTCS << 0) & 0x0000ffff))

/* Table 33. General-Purpose Timer <Counter> Register */

#define I_GPTCR (\
  ((I_GPTCR_RTCC << 0) & 0xffffffff))

/* Table 34. General-Purpose Timer <Scaler> Register */

#define I_GPTSR (\
  ((I_GPTSR_RTCC << 0) & 0x0000ffff))

/* Table 35. Timer Control Register */

#define I_TIMCTR (\
  ((I_TIMCTR_RTCSL << 11) & 0x00000800) | \
  ((I_TIMCTR_RTCE << 10) & 0x00000400) | \
  ((I_TIMCTR_RTCCL << 9) & 0x00000200) | \
  ((I_TIMCTR_RTCR << 8) & 0x00000100) | \
  ((I_TIMCTR_BHLT << 6) & 0x00000040) | \
  ((I_TIMCTR_AHLT << 5) & 0x00000020) | \
  ((I_TIMCTR_PHLT << 4) & 0x00000010) | \
  ((I_TIMCTR_GPTSL << 3) & 0x00000008) | \
  ((I_TIMCTR_GPTE << 2) & 0x00000004) | \
  ((I_TIMCTR_GPTCL << 1) & 0x00000002) | \
  ((I_TIMCTR_GPTR << 0) & 0x00000001))

/* Table 36. GPI Configuration Register */

#define I_GPICNFR (\
  ((I_GPICNFR_R_F << 8) & 0x0000ff00) | \
  ((I_GPICNFR_I_O << 0) & 0x000000ff))

/* Table 37. GPI Data Register */

#define I_GPIDATR (\
  ((I_GPIDATR_GPID << 0) & 0x000000ff))

/* Table 38. UART 'A' Rx and Tx Register */

#define I_UARTAR (\
  ((I_UARTAR_RTDA << 0) & 0x000000ff))

/* Table 39. UART 'B' Rx and Tx Register */

#define I_UARTBR (\
  ((I_UARTBR_RTDB << 0) & 0x000000ff))

/* Table 40. UART Status Register */

#define I_UARTSR (\
  ((I_UARTSR_CUB << 23) & 0x00800000) | \
  ((I_UARTSR_OEB << 22) & 0x00400000) | \
  ((I_UARTSR_PEB << 21) & 0x00200000) | \
  ((I_UARTSR_EFB << 20) & 0x00100000) | \
  ((I_UARTSR_THEB << 18) & 0x00040000) | \
  ((I_UARTSR_TSEB << 17) & 0x00020000) | \
  ((I_UARTSR_DRB << 16) & 0x00010000) | \
  ((I_UARTSR_CUB << 7) & 0x00000080) | \
  ((I_UARTSR_OEB << 6) & 0x00000040) | \
  ((I_UARTSR_PEB << 5) & 0x00000020) | \
  ((I_UARTSR_EFB << 4) & 0x00000010) | \
  ((I_UARTSR_THEB << 2) & 0x00000004) | \
  ((I_UARTSR_TSEB << 1) & 0x00000002) | \
  ((I_UARTSR_DRB << 0) & 0x00000001))

#endif /* not _REGISTER_MACROS_H_ */

