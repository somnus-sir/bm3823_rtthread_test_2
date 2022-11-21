/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author      Notes
 * 2010-11-17     yi.qiu      first version
 */

#include <rtthread.h>
#include <rtm.h>

#include "dlmodule.h"

void* dlsym(void *handle, const char* symbol)
{
    int i;
    struct rt_dlmodule *module;
    
    RT_ASSERT(handle != RT_NULL);

    module = (struct rt_dlmodule *)handle;

    for(i=0; i<module->nsym; i++)
    {
        if (rt_strcmp(module->symtab[i].name, symbol) == 0)
            return (void*)module->symtab[i].addr;
    }

    return RT_NULL;
}
RTM_EXPORT(dlsym)
