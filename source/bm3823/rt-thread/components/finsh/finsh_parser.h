/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-03-22     Bernard      first version
 */
#ifndef __FINSH_PARSER_H__
#define __FINSH_PARSER_H__

#include <finsh.h>

int finsh_parser_init(struct finsh_parser* self);
void finsh_parser_run(struct finsh_parser* self, const uint8_t* string);

#endif
