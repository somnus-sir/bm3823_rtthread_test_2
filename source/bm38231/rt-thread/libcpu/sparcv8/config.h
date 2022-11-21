/**************************************************************************
 *
 * Filename:
 *
 *   config.h
 *
 * Description:
 *
 *   This file defines the initial values for the writable fields of the
 *   ERC32 system registers
 *
 *   See TSC695F, Rad Hard 32-Bit SPARC Embedded Processor Users' Manual,
 *   22 March 2001, Published by Atmel Wireless, for details of system
 *   registers.
 *
 *  Credits:
 *
 *   Copyright (c) 1998, 2010 XGC Technology (www.xgc.com)
 *
 * License:
 *
 *   Permission to use copy, modify, and distribute this software for any
 *   purpose without fee is hereby granted. This software is provided "as
 *   is", without any express or implied warranty.
 *
 * Revision:
 *
 *    $Id: config.h,v 1.3 2010/12/01 10:18:12 nettleto Exp $
 *
 **************************************************************************/

/*
 * SUPERVISOR_MODE: Define this where your application should run in
 * supervisor mode. This is not usually necessary as operations that need
 * supervisor mode are written within a protected object, which
 * automatically sets the mode.
 *
 * The factory setting is:
 *
 *   #undef SUPERVISOR_MODE
 */

#define SUPERVISOR_MODE

/*
 * HAVE_SYSTEM_CALLS: Define this if you wish to have a handler for system
 * calls. The default system call handler supports input and output via
 * the UART (using read and write system calls). You may write your own
 * handler that supports other devices too. See the source code
 * libc/sys/schandler.c for details. Note that the Ada packages Text_IO,
 * Direct_IO and Sequential_IO all make system calls. Note also that the
 * ERC32 simulator will intercept system calls and map them to host
 * computer calls. This allows (for example) Text_IO to read and write
 * host computer files.
 *
 * The factory setting is:
 *
 *   #undef HAVE_SYSTEM_CALLS
 */

#define HAVE_SYSTEM_CALLS

/*
 * HAVE_CONSTRUCTORS is to be defined to include the code that executes
 * static constructors. This is a C++ feature, but by means of the
 * __attribute__ feature in C, and the pragma Attribute feature in Ada,
 * any function or subprogram can be required to run as a constructor.
 * We enable this by default because this file is common to all supported
 * languages, including C++. For Ada-only applications, you may save a
 * little code space by commenting out the definition.
 *
 * The factory setting is:
 *
 *   #define HAVE_CONSTRUCTORS
 */

#define HAVE_CONSTRUCTORS

/*
 * ALSO_UNMASK: While it is good practice to attach interrupts at
 * elaboration time, it is sometimes necessary to unmask much later. We
 * therefore offer the programmer the option of unmasking within the call
 * of attach_handler, or sometime later by code written by the application
 * programmer.  If you wish to unmask the interrupt immediately after it
 * is attached, then the following statement should read "#define
 * ALSO_UNMASK", otherwise it should read "#undef ALSO_UNMASK".
 *
 * The factory setting is:
 *
 *   #define ALSO_UNMASK
 */

#define ALSO_UNMASK

/*
 * ACCESS_PROTECTION: Define this if you wish to protect instructions from
 * being overwritten. Access protection only applies to programs that are
 * resident in RAM. Programs resident in the boot PROM cannot use it.
 *
 * The factory setting is:
 *
 *   #define ACCESS_PROTECTION
 */

#define ACCESS_PROTECTION

/*
 * WDOG: Define WDOG if you want the watchdog to interrupt after a period
 * of inattention. WDOG_FREQUENCY is the frequency in Hz of the watchdog
 * clock. This macro does not set the frequency: that is done in the
 * hardware. It is used to set the watchdog scaler. The watchdog clock on
 * the Temic Starter Kit board runs at 1.8432 MHz.
 *
 * The factory setting is:
 *
 *   #define WDOG
 *   #define WDOG_FREQUENCY 1843200
 */

#undef WDOG
#define WDOG_FREQUENCY 1843200

/*
 * _CLOCK_FREQUENCY gives the ERC32 clock frequency in MHz. This macro does
 * not set the frequency, that is done by the hardware. It is used to set
 * the pre-scalar registers RTCSR and GPTSR so that the associated timer
 * registers RTCCR and GTPCR are clocked at 1MHz. If your clock frequency
 * is not a whole number of microseconds, then you should set
 * _CLOCK_FREQUENCY to the nearest number of MHz and expect small
 * inaccuracies in the timing of Ada delays.
 *
 * The factory setting is:
 *
 *   #define _CLOCK_FREQUENCY 20
 *
 *     which says the clock frequency to 20 MHz.
 */

#define _CLOCK_FREQUENCY 16

/*
 * __CPU_TIME is set if we wish to record the cpu time used by a task. The
 * default is __CPU_TIME is not defined. Note: no use is made of CPU time
 * information in this version.
 *
 * The factory setting is:
 *
 *   #undef __CPU_TIME
 */

#undef __CPU_TIME


/*************************************************************************
 *
 * End of config.h
 *
 *************************************************************************/

