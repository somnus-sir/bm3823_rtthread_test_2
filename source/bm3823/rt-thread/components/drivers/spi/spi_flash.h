/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2016/5/20      bernard      the first version
 */

#ifndef SPI_FLASH_H__
#define SPI_FLASH_H__

struct spi_flash_device
{
    struct rt_device                flash_device;
    struct rt_device_blk_geometry   geometry;
    struct rt_spi_device *          rt_spi_device;
    struct rt_mutex                 lock;
    void *                          user_data;
};

typedef struct spi_flash_device *rt_spi_flash_device_t;

#ifdef RT_USING_MTD_NOR
struct spi_flash_mtd
{
    struct rt_mtd_nor_device 			mtd_device;
    struct rt_spi_device *     			rt_spi_device;
    struct rt_mutex            			lock;
    void *                     			user_data;
};
#endif

#endif
