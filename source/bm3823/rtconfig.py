import os
# CPU options
ARCH='sparcv8'
CPU ='bm3803'

if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')
else:
    RTT_ROOT = '../..'

# toolchains options
CROSS_TOOL  = 'gcc'

if os.getenv('RTT_CC'):
	CROSS_TOOL = os.getenv('RTT_CC')

if  CROSS_TOOL == 'gcc':
	PLATFORM    = 'gcc'
	EXEC_PATH   = r'D:\env\tools\gnu_gcc\sparc-elf-4.4.2-mingw\bin'
else:
    print('================ERROR===========================')
    print('Not support %s yet!' % CROSS_TOOL)
    print('=================================================')
    exit(0)

if os.getenv('RTT_EXEC_PATH'):
	EXEC_PATH = os.getenv('RTT_EXEC_PATH')

BUILD       = 'debug'

PREFIX = 'sparc-elf-'
CC = PREFIX + 'gcc'
AS = PREFIX + 'gcc'
AR = PREFIX + 'ar'
LINK = PREFIX + 'gcc'
TARGET_EXT = 'elf'
SIZE = PREFIX + 'size'
OBJDUMP = PREFIX + 'objdump'
OBJCPY = PREFIX + 'objcopy'
READELF = PREFIX + 'readelf'

DEVICE = '  -O0 -g3 -ggdb -Wall -mcpu=v8 -mno-fpu -c '
CFLAGS = DEVICE + '-fmessage-length=0 '
AFLAGS = DEVICE + '-fmessage-length=0'
LFLAGS = ' -mcpu=v8 -mno-fpu --gc-sections  -nostartfiles -Ttext=0x20000000 -n -N -T linksparc.ld -o rtthread.elf '
CXXFLAGS = CFLAGS

CPATH = ''
LPATH = ''

if BUILD == 'debug':
    CFLAGS += ' -O0 '
    AFLAGS += ' '
else:
    CFLAGS += ' -O2'

DUMP_ACTION = OBJDUMP + ' -D -S $TARGET > rtt.asm\n'
READELF_ACTION = READELF + ' -a $TARGET > rtt.map\n'
POST_ACTION = OBJCPY + ' -O binary $TARGET rtthread.bin\n' + SIZE + ' $TARGET \n'
