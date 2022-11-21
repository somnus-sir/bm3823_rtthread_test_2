/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-11-17     yi.qiu       first version
 */

#include <rtthread.h>
#include <rtm.h>

#include "dlmodule.h"

int dlclose(void *handle)
{
    struct rt_dlmodule *module;

    RT_ASSERT(handle != RT_NULL);

    module = (struct rt_dlmodule *)handle;

    rt_enter_critical();
    module->nref--;
    if (module->nref <= 0)
    {
        rt_exit_critical();

        dlmodule_destroy(module);
    }
    else
    {
        rt_exit_critical();
    }

    return RT_TRUE;
}
RTM_EXPORT(dlclose)
