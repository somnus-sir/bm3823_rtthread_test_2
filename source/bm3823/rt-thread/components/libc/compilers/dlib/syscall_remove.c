/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2015-01-28     Bernard      first version
 */
#include <rtthread.h>
#ifdef RT_USING_DFS
#include <dfs_file.h>
#endif
#include <yfuns.h>

#pragma module_name = "?remove"
int remove(const char *val)
{
#ifdef RT_USING_DFS
    dfs_file_unlink(val);
#endif

    return 0;
}
