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
#include <leon2.h>

#ifndef __ASSEMBLER__

struct lregs
{                                           // address = 0x81000000
    volatile unsigned int mcfg1;            /* 0x00 */
    volatile unsigned int mcfg2;
    volatile unsigned int mcfg3;
    volatile unsigned int failaddr;

    volatile unsigned int memstatus;         /* 0x10 */
    volatile unsigned int dummy0;        //old is cachectrl;
    volatile unsigned int dummy1;        //old is powerdown;
    volatile unsigned int writeprot1;

    volatile unsigned int writeprot2;       /* 0x20 */
    volatile unsigned int dummy2;                 //old is pcr;
    volatile unsigned int dummy3;
    volatile unsigned int dummy4;

    volatile unsigned int dummy5;           /* 0x30 */
    volatile unsigned int dummy6;
    volatile unsigned int dummy7;
    volatile unsigned int dummy8;

    volatile unsigned int timercnt1;        /* 0x40 */
    volatile unsigned int timerload1;
    volatile unsigned int timerctrl1;
    volatile unsigned int wdog;

    volatile unsigned int timercnt2;        /* 0x50 */
    volatile unsigned int timerload2;
    volatile unsigned int timerctrl2;
    volatile unsigned int dummy9;

    volatile unsigned int scalercnt;        /* 0x60 */
    volatile unsigned int scalerload;
    volatile unsigned int dummy10;
    volatile unsigned int dummy11;

    volatile unsigned int uartdata1;        /* 0x70 */
    volatile unsigned int uartstatus1;
    volatile unsigned int uartctrl1;
    volatile unsigned int uartscaler1;

    volatile unsigned int uartdata2;        /* 0x80 */
    volatile unsigned int uartstatus2;
    volatile unsigned int uartctrl2;
    volatile unsigned int uartscaler2;

};

#endif
/* part 2 control2 registers */
struct lregs2
{                                   //address = 0x81000100
    volatile unsigned int mecfg1;   /* 0x100 */
    volatile unsigned int mecfg2;
    volatile unsigned int dummy1;      
    volatile unsigned int dummy2;
};

/* part 3 uart fifo registers */
struct lregs_uart_fifo
{                                            //address = 0x810001C0
    volatile unsigned int uart3_baud_freq;   /* 0x1C0 */
    volatile unsigned int uart3_setup;
    volatile unsigned int uart3_status;       
    volatile unsigned int uart3_data;
             
    volatile unsigned int uart3_clr_status;  /* 0x1D0 */     
    volatile unsigned int uart3_no_tx_data;  
    volatile unsigned int uart3_int_en;
    volatile unsigned int dummy1;  
    
    volatile unsigned int uart4_baud_freq;   /* 0x1E0 */
    volatile unsigned int uart4_setup;
    volatile unsigned int uart4_status;       
    volatile unsigned int uart4_data; 
            
    volatile unsigned int uart4_clr_status;      
    volatile unsigned int uart4_no_tx_data;  /* 0x1F0 */
    volatile unsigned int uart4_int_en;
    volatile unsigned int dummy2;    
};

/* part 4 cnt registers */
struct lregs_cnt
{                                     //address = 0x81000210
    volatile unsigned int cnt1_ctrl;   /* 0x210 */
    volatile unsigned int cnt1_data;
    volatile unsigned int cnt1_scaler;       
    volatile unsigned int dummy1;
             
    volatile unsigned int cnt2_ctrl;   /* 0x220 */
    volatile unsigned int cnt2_data;
    volatile unsigned int cnt2_scaler;       
    volatile unsigned int dummy2;
             
    volatile unsigned int cnt3_ctrl;   /* 0x230 */
    volatile unsigned int cnt3_data;
    volatile unsigned int cnt3_scaler;       
    volatile unsigned int dummy3;
             
    volatile unsigned int cnt4_ctrl;   /* 0x240 */
    volatile unsigned int cnt4_data;
    volatile unsigned int cnt4_scaler;       
    volatile unsigned int dummy4;
             
    volatile unsigned int cnt5_ctrl;   /* 0x250 */
    volatile unsigned int cnt5_data;
    volatile unsigned int cnt5_scaler;       
    volatile unsigned int dummy5;
             
    volatile unsigned int cnt6_ctrl;   /* 0x260 */
    volatile unsigned int cnt6_data;
    volatile unsigned int cnt6_scaler;       
    volatile unsigned int dummy6;
};

/* part 5 pwm registers */
struct lregs_pwm
{                                                //address = 0x81000300
    volatile unsigned int pwm_ctrl;               /* 0x300 */
    volatile unsigned int dummy0;
    volatile unsigned int dummy1;       
    volatile unsigned int dummy2;
             
    volatile unsigned int pwm1_count;      /* 0x310 */
    volatile unsigned int pwm1_preload1;       
    volatile unsigned int pwm1_preload2;
    volatile unsigned int pwm1_config;

    volatile unsigned int pwm2_count;      /* 0x320 */
    volatile unsigned int pwm2_preload1;       
    volatile unsigned int pwm2_preload2;
    volatile unsigned int pwm2_config;

    volatile unsigned int pwm3_count;     /* 0x330 */ 
    volatile unsigned int pwm3_preload1;       
    volatile unsigned int pwm3_preload2;
    volatile unsigned int pwm3_config;
    
    volatile unsigned int pwm4_count;    /* 0x340 */  
    volatile unsigned int pwm4_preload1;       
    volatile unsigned int pwm4_preload2;
    volatile unsigned int pwm4_config;
    
    volatile unsigned int pwm5_count;    /* 0x350 */  
    volatile unsigned int pwm5_preload1;       
    volatile unsigned int pwm5_preload2;
    volatile unsigned int pwm5_config;

    volatile unsigned int pwm6_count;   /* 0x360 */   
    volatile unsigned int pwm6_preload1;       
    volatile unsigned int pwm6_preload2;
    volatile unsigned int pwm6_config;
};

/* part 6 gpio registers */
struct lregs_gpio
{                                               //address = 0x81000400
    volatile unsigned int piodata;               /* 0x400 */
    volatile unsigned int dummy1;
    volatile unsigned int piodir;       
    volatile unsigned int dummy2;
             
    volatile unsigned int pioscaler;      /* 0x410 */
    volatile unsigned int pioscl_clken;       
    volatile unsigned int pioirq;
    volatile unsigned int dummy3;

    volatile unsigned int pio0data0;      /* 0x420 */
    volatile unsigned int pio0data1;       
    volatile unsigned int pio1data0;
    volatile unsigned int pio1data1;

    volatile unsigned int pio2data0;      /* 0x430 */
    volatile unsigned int pio2data1;       
    volatile unsigned int pio3data0;
    volatile unsigned int pio3data1;
};

/* part 7 spi registers */
struct lregs_spi
{                                                 //address = 0x81000560
    volatile unsigned int spi0_ctrl;               /* 0x560 */
    volatile unsigned int spi0_status;
    volatile unsigned int spi0_data;       
    volatile unsigned int spi0_scaler;
             
    volatile unsigned int spi0_length;      /* 0x570 */
    volatile unsigned int spi0_csn;       
    volatile unsigned int dummy1;
    volatile unsigned int dummy2;

    volatile unsigned int spi1_ctrl;               /* 0x580 */
    volatile unsigned int spi1_status;
    volatile unsigned int spi1_data;       
    volatile unsigned int spi1_scaler;
             
    volatile unsigned int spi1_length;      /* 0x590 */
    volatile unsigned int spi1_csn;       
    volatile unsigned int dummy3;
    volatile unsigned int dummy4;
};

/* part 8 i2c0 registers */
struct lregs_i2c0
{                                                 //address = 0x81000800
    volatile unsigned int i2c0_flag;               /* 0x800 */
    volatile unsigned int i2c0_ctrl;
    volatile unsigned int i2c0_speed;       
    volatile unsigned int i2c0_data;
             
    volatile unsigned int i2c0_saddr1;      /* 0x810 */
    volatile unsigned int i2c0_saddr0;       
    volatile unsigned int i2c0_status;
    volatile unsigned int i2c0_irqmask;

    volatile unsigned int i2c0_mdaddr;           /* 0x820 */
    volatile unsigned int i2c0_maddr1;
    volatile unsigned int i2c0_maddr2;       
    volatile unsigned int i2c0_mode;
             
    volatile unsigned int i2c0_freq;       /* 0x830 */
    volatile unsigned int dummy0;       
    volatile unsigned int dummy1;
    volatile unsigned int dummy2;
};

/* part 9 i2c1 registers */
struct lregs_i2c1
{                                                  //address = 0x81000900
    volatile unsigned int i2c1_flag;               /* 0x900 */
    volatile unsigned int i2c1_ctrl;
    volatile unsigned int i2c1_speed;       
    volatile unsigned int i2c1_data;
             
    volatile unsigned int i2c1_saddr1;      /* 0x910 */
    volatile unsigned int i2c1_saddr0;       
    volatile unsigned int i2c1_status;
    volatile unsigned int i2c1_irqmask;

    volatile unsigned int i2c1_mdaddr;           /* 0x920 */
    volatile unsigned int i2c1_maddr1;
    volatile unsigned int i2c1_maddr2;       
    volatile unsigned int i2c1_mode;
             
    volatile unsigned int i2c1_freq;       /* 0x930 */
    volatile unsigned int dummy0;       
    volatile unsigned int dummy1;
    volatile unsigned int dummy2;
};

/* part 10 contrl2 registers */
struct hregs
{                                               //address = 0x80000000
    volatile unsigned int dummy0;               /* 0x00 */
    volatile unsigned int dummy1;
    volatile unsigned int dummy2;       
    volatile unsigned int failaddr;
    
    volatile unsigned int memstatus;           /* 0x10 */
    volatile unsigned int cachectrl;
    volatile unsigned int powerdown;       
    volatile unsigned int dummy3; 
       
    volatile unsigned int dummy4;            /* 0x20 */
    volatile unsigned int pconfig;
    volatile unsigned int dummy5;       
    volatile unsigned int dummy6; 
    
    volatile unsigned int imcfg;         /* 0x30 */
};

/* part 11 irq registers */
struct hregs_irq
{                                               //address = 0x80000090
    volatile unsigned int irq1mask_pri;          /* 0x90 */
    volatile unsigned int irq1force_pend;
    volatile unsigned int irq1subpri;
    volatile unsigned int irq1clear;

    volatile unsigned int dummy1;          /* 0xA0 */
    volatile unsigned int dummy2;
    volatile unsigned int dummy3;
    volatile unsigned int dummy4;

    volatile unsigned int irq2mask;           /* 0xB0 */
    volatile unsigned int irq2pend;
    volatile unsigned int irq2state_clear;
    volatile unsigned int dummy5;


};
/* part 12 extern irq registers */
struct hregs_exirq
{                                         //address = 0x800003c0
      volatile unsigned int config;       /* 0x3c0 */
}; 

/* part 13 dcom registers */
struct hregs_dcom
{                                     //address = 0x800000c0
    volatile unsigned int dummy;      /* 0xc0 */
    volatile unsigned int status;            
    volatile unsigned int ctrl;
    volatile unsigned int baud_reload;       
};

/* part 14 pci registers */
struct hregs_pci
{                                     //address = 0x800000d0
    volatile unsigned int reset;      /* 0xd0 */
    volatile unsigned int dummy0;            
    volatile unsigned int dummy1;
    volatile unsigned int dummy2;       
};

/* part 15 cache check registers */
struct hregs_ccr
{                                      //address = 0x80000110
    volatile unsigned int cctrl1;      /* 0x110 */
    volatile unsigned int cctrl2;            
    volatile unsigned int cctrl3;
    volatile unsigned int dummy;       
}; 

/* part 16 gmac registers */
struct gmac_mac
{                                        //address = 0xB0000000
    volatile unsigned int config;        /* 0x0 */
    volatile unsigned int framfilter;
    volatile unsigned int hashtabhi;
    volatile unsigned int hashtablo;
    
    volatile unsigned int gmiiaddr;      /* 0x10 */
    volatile unsigned int gmiidata;
    volatile unsigned int flowctrl; 
    volatile unsigned int dummy0;
    
    volatile unsigned int version;       /* 0x20 */
    volatile unsigned int debug;
    volatile unsigned int dummy1[2];
    
    volatile unsigned int dummy2[3];     /* 0x30 */
    volatile unsigned int intmask;
    
    volatile unsigned int macaddr0hi;    /* 0x40 */
    volatile unsigned int macaddr0lo;    
    volatile unsigned int macaddr1hi;
    volatile unsigned int macaddr1lo;
    
    volatile unsigned int dummy3[28];
    
    volatile unsigned int anctrl;                /* 0xC0 */
    volatile unsigned int anstatus;
};

struct gmac_dma
{                                           //address = 0xB0001000
        volatile unsigned int busmode;      /* 0x0 */
        volatile unsigned int txpolldemand;
        volatile unsigned int rxpolldemand;
        volatile unsigned int rxdesclistaddr;
        
        volatile unsigned int txdesclistaddr;   /* 0x10 */
        volatile unsigned int status;
        volatile unsigned int opmode;
        volatile unsigned int irqenable;
        
        volatile unsigned int missf_bufovcnt;   /* 0x20 */
        volatile unsigned int reirqwdogt;
        volatile unsigned int axibusmode;
        volatile unsigned int axibusstatus;
        
        volatile unsigned int dummy[6];         /* 0x30 */
        volatile unsigned int curhosttxdescr;
        volatile unsigned int curhostrxdescr;
        
        volatile unsigned int curhosttxbufaddr;  /* 0x40 */
        volatile unsigned int curhostrxbufaddr; 
};

struct tx_desc{                        
        volatile unsigned int status;
        volatile unsigned int count;
        volatile unsigned int buf1_addr;
        volatile unsigned int buf2_addr;
        
        volatile unsigned int dummy0;
        volatile unsigned int dummy1;
        volatile unsigned int retimestamplo;
        volatile unsigned int retimestamphi;
};

struct rx_desc{                        
        volatile unsigned int status;
        volatile unsigned int count;
        volatile unsigned int buf1_addr;
        volatile unsigned int buf2_addr;
        
        volatile unsigned int extstatus;
        volatile unsigned int dummy1;
        volatile unsigned int retimestamplo;
        volatile unsigned int retimestamphi;
};
    
/* control registers */

#define    HREGS    0x80000000
#define    LREGS    0x81000000
#define    MCFG1    0x00
#define    MCFG2    0x04
#define    MCFG3    0x08
#define    FADDR    0x0C
#define    MSTAT    0x10
#define    CCTRL    0x14
#define    PWDOWN   0x18
#define    WPROT1   0x1C
#define    WPROT2   0x20
#define    PCONF    0x24
#define    TCNT0    0x40
#define    TRLD0    0x44
#define    TCTRL0   0x48
#define    WDOG     0x4C
#define    TCNT1    0x50
#define    TRLD1    0x54
#define    TCTRL1   0x58
#define    SCNT     0x60
#define    SRLD     0x64
#define    UDATA0   0x70
#define    USTAT0   0x74
#define    UCTRL0   0x78
#define    USCAL0   0x7c
#define    UDATA1   0x80
#define    USTAT1   0x84
#define    UCTRL1   0x88
#define    USCAL1   0x8c


/* ASI codes */

#define ASI_IFLUSH    0x5
#define ASI_DFLUSH    0x6
#define ASI_ITAG      0xC
#define ASI_IDATA     0xD
#define ASI_DTAG      0xE
#define ASI_DDATA     0xF

/* memory areas */

#define CRAM      0x20000000
#define IOAREA    0x10000000

/* Some bit field masks */

#define CCTRL_FLUSHING_MASK 0x0c000

#define RFE_CONF_BIT     30
#define RFE_CONF_MASK    3
#define CPP_CONF_BIT     19
#define CPP_CONF_MASK    3
#define FPU_CONF_BIT     4
#define FPU_CONF_MASK    3
#define CPTE_MASK        (3 << 17)
#define MUL_CONF_BIT     8
#define MAC_CONF_BIT     25
#define DIV_CONF_BIT     9
#define REDAC_CONF_BIT   9
#define PEDAC_CONF_BIT   8
#define MEDAC_CONF_BIT   27
#define ITE_BIT          12
#define IDE_BIT          10
#define DTE_BIT          8
#define DDE_BIT          6
#define CE_CLEAR         0x3fc0;

//timer
#define  COUNT_EN       0x1
#define  RELOAD_COUNT   0x2
#define  LOAD_COUNT     0x4
#define  WDEN           0x10

//#define CPU_FREQ     300000000  //HVP
#define CPU_FREQ     100000000  //BM3823
#define BUS_2_FREQ   (CPU_FREQ/3)
#define CPU_FREQ2    CPU_FREQ/3

struct sparc_rtthread_stack 
{
    unsigned long regs[8*2];
    unsigned long psr;
    unsigned long wim;
    unsigned long pc;
    unsigned long o0;
};
