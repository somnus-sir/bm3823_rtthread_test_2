/*
 * RT-Thread Space Special Edition
 * 
 * Copyright (c) 2011-2020, Shanghai Real-Thread Electronic Technology Co., Ltd.
 *
 * All rights reserved.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2008-08-14     Bernard      the first version
 */
#ifndef __CTYPE_H__
#define __CTYPE_H__

int isprint(int c) __attribute__ ((__const__));
int isalpha (int c) __attribute__ ((__const__));
int isdigit (int ch) __attribute__ ((__const__));
int isspace(int ch) __attribute__ ((__const__));

#endif
