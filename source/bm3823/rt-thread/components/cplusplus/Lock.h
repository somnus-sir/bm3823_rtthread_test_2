/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2016/10/1      Bernard      The first version
 */

#pragma once

#include <stdint.h>
#include <string.h>

namespace rtthread {

class Lock
{
public:
    Lock(Mutex& mutex) : m(mutex) {m.lock();}
    ~Lock() {m.unlock();}

protected:
    Mutex &m;
};

}
