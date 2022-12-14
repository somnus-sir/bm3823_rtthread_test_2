/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 */
#ifndef __RTT_STATFS_H__
#define __RTT_STATFS_H__

#include <rtthread.h>

struct statfs
{
	rt_size_t f_bsize; 	 /* block size */
	rt_size_t f_blocks;  /* total data blocks in file system */
	rt_size_t f_bfree;	 /* free blocks in file system */
};

#endif
