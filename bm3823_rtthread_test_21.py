
import os
from pickle import TRUE
from telnetlib import PRAGMA_HEARTBEAT, SE
from se import *
import se_system as ss
import threading
import time
from ctypes import *
import csv
import shutil
from itertools import islice
import sys
# sys.path.append(r"C:\Users\chenl\Desktop\autotest\cicd")
# from fun import *

# csv_path=r"C:\Users\chenl\Desktop\autotest\cicd\data.csv"
# cpu_name="sparc_v8_0"
# binary_path=r"binary\rtthread.elf"
# testcase_namepath=r"C:\Users\chenl\workspace\targets\bm3823_rtthread_test\testname.txt"

def assertequal(a,b):
	if a==b:
		return True

	else:
		return False

def transform(value):
	if not 0 <= value <=2147483647:
		value -=4294967296
	return value


test_add_data=[
	(-1,0,-1),
	(1,-2,-1),
	(-10,5,-5),
	(-4,3,-1),
	(2,3,5),
	(4,2,6)]

i=-1
def func():
	try:
		print(test_add_data)
		SE_define_conf("bm3823_rtthread_test_2.json")
		SE_load_binary("sparc_v8_0","binary/rtthread.elf")
		SE_enable_parse_symbol("sparc_v8_0","binary/rtthread.elf")
		SE_init_ok()
		SE_run()
		# # addr=SE_get_global_variable_addr("sparc_v8_0","tst_c")
		addr=SE_get_global_variable_addr("sparc_v8_0","tst_a")
		print(addr)
		addr=SE_get_global_variable_addr("sparc_v8_0","tst_b")
		print(addr)
		print("_______________________________")
		# print(SE_get_global_variable_value("sparc_v8_0","tst_a",4,TY_INT))
		SE_print(SE_get_global_variable_value("sparc_v8_0","tst_a",4,TY_INT))
		SE_print(SE_get_global_variable_value("sparc_v8_0","tst_b",4,TY_INT))
		SE_print(SE_get_global_variable_value("sparc_v8_0","tst_c",4,TY_INT))
		SE_print("hello world")
		# def write_mem(data):
		# 	global i
		# 	if i <len(test_add_data):

		# 		SE_print(i)
		# 		# print(i)
		# 		SE_set_global_variable_value("sparc_v8_0","tst_a",test_add_data[i][0],4,TY_INT)
		# 		SE_set_global_variable_value("sparc_v8_0","tst_b",test_add_data[i][1],4,TY_INT)

		# 		print("-------------")
		# 		tst_c=SE_get_global_variable_value("sparc_v8_0","tst_c",4,TY_INT)
		# 		tst_c=(transform(tst_c))
		# 		print(SE_get_global_variable_value("sparc_v8_0","tst_a",4,TY_INT))
		# 		print(SE_get_global_variable_value("sparc_v8_0","tst_b",4,TY_INT))

		# 		SE_print(tst_c)
		# 		print("---------------------------")
		# 		print(tst_c)
		# 		print(test_add_data[i][-1])
		# 		print(assertequal(tst_c,test_add_data[i][-1]))
		# 		print("-------------")
		# 		# SE_print(SE_set_global_variable_value("sparc_v8_0","tst_b",13,4,TY_INT))

		# 		# print(test_add_data[i][-1])
		# 		print("test is ok!!!!")


		# 		print(test_add_data[i][0])
		# 	# if i<len(test_add_data)+1:
		# 		i+=1
		# 	# if i>3:
		# 	else:
		# 		pass
		# 	# 	SE_del_watch_on_mem(ret)
		# 	SE_sleep(0.01)

		# 	# print(i[2])
		# 	# print("set ok!!!")


		# 	# print("")
		# #
		def write_mem(data):
			SE_print("callback")
			print("dasdadsads")
		
		# ret = SE_set_watch_on_mem("memory_space_0",MO_READ,addr,OP_WORD_TYPE,10,write_mem,None)
		ret = SE_set_watch_on_mem("memory_space_0",MO_WRITE,addr,OP_WORD_TYPE,10,write_mem,None)
		# if i == len(test_add_data)-1:
		# 	SE_del_watch_on_mem(ret)

	except Exception as ep:
		print(ep)

func()