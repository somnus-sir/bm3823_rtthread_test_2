import os
import se
import se_system as ss
import threading
import time
from ctypes import *
import csv
import shutil
from itertools import islice
import sys
sys.path.append(r"C:\Users\chenl\Desktop\autotest\cicd")
from fun import *

csv_path=r"C:\Users\chenl\Desktop\autotest\cicd\data.csv"
cpu_name="sparc_v8_0"
binary_path=r"binary\rtthread.elf"
testcase_namepath=r"C:\Users\chenl\workspace\targets\bm3823_rtthread_test\testname.txt"

# ret = None
# cnt = 0
# class thread(threading.Thread):
# 	def __init__(self,func):
# 		threading.Thread.__init__(self)
# 		self.func=func
# 		self.setDaemon(True)
# 		self.ThreadStop=False
# 	def run(self):
# 		while self.ThreadStop == False:
# 			self.func()
# 			self.ThreadStop = True

# 	def stop(self):
# 		self.ThreadStop=True

def func():
	# se.SE_enable_parse_symbol(cpu_name,"rtthread.elf")
	# print(12345)
	
	# se.SE_enable_parse_symbol(cpu_name,"rtthread.elf")
	
	print(suite)
	list=[]
	#se.SE_stop()
	# se.SE_reset()
	# se.SE_define_conf("bm3823_rtthread_test.json")
	# se.SE_load_binary(cpu_name,binary_path)
	# se.SE_init_ok()
	for i in suite:
		addr1=se.SE_get_global_variable_addr(cpu_name,i.var_name)
		print("ȫ�ֱ���{}�ĵ�ַΪ{}".format(i.var_name,addr1))
		print("ȫ�ֱ���{}��ֵΪ{}".format(i.var_name,se.SE_get_global_variable_value(cpu_name,i.var_name,4,se.TY_INT)))
		se.SE_set_global_variable_value(cpu_name,i.var_name,int(i.ncentives),4,se.TY_INT)
		b=se.SE_get_global_variable_value(cpu_name,i.var_name,4,se.TY_INT)
		print("�޸ĺ�ȫ�ֱ���{}��ֵΪ{}".format(i.var_name,b))
		addr1=se.SE_get_global_variable_addr(cpu_name,i.var_name)
		print("�޸ĺ��ȫ�ֱ���{}�ĵ�ַΪ{}".format(i.var_name,addr1))
		i.list.append(b)
		if int(i.ncentives)==b:
			test_result="Test_PASS"
		else :
			test_result="Test_ERROR"
		i.list.append(test_result)
		print(i.list)
		list.append(i.list)
	return list
	#se.SE_run()
	#time.sleep(5)

a=read_testdata(csv_path)
suite=read_params(a)

testcase_name=get
# th=thread(func)
# th.start()
b=func()
os.remove(r"C:\Users\chenl\Desktop\autotest\cicd\data.csv")
write_csv_result(b,)