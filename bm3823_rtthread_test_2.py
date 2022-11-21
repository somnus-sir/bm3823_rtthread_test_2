
import os
from telnetlib import PRAGMA_HEARTBEAT, SE
from se import *
import se_system as ss
import threading
import time
from ctypes import *
import csv

def assertequal(a,b):
	if a==b:
		return True

	else:
		return False

def transform(value):
	if not 0 <= value <=2147483647:
		value -=4294967296
	return value

def read_data():
	data=[]
	with open("testdata.csv") as f:
		f_csv=csv.reader(f)
		headers=next(f_csv)
		for row in f_csv:
			data2=[]
			for i in row:
				data2.append(int(i))
			data.append(data2)

	return data

def create_report():
	try:
		if os.path.exists("test_result.txt"):
			os.remove("test_result.txt")
		with open("test_result.txt","w",encoding="utf-8") as fq:
			fq.write("testcasenum,tst_a,tst_b,tst_c,experct_c,testresult\n")
			fq.close()
	except Exception as ep:
		print(ep)
a=b=i=0

def func():
	try:
		create_report()
		data1 = read_data()
		SE_define_conf("bm3823_rtthread_test_2.json")
		SE_load_binary("sparc_v8_0","binary/rtthread.elf")
		SE_enable_parse_symbol("sparc_v8_0","binary/rtthread.elf")
		SE_init_ok()
		SE_run()
		addr_a=SE_get_global_variable_addr("sparc_v8_0","tst_a")
		addr_b=SE_get_global_variable_addr("sparc_v8_0","tst_b")
		addr_c=SE_get_global_variable_addr("sparc_v8_0","tst_c")
		# SE_sleep(10)
		SE_stop()
		SE_run()
		
		def write_mem_tst_a(da):
			global a
			if a==0:
				a+=1
			else:
				if a <= len(data1):
					SE_set_global_variable_value("sparc_v8_0","tst_a",transform(data1[a-1][0]),4,TY_INT)	
					SE_print(data1[a-1][0])
					a+=1
				else:
					pass	
		def write_mem_tst_b(da):
			global b
			if b==0:
				b += 1
			else:
				if b <= len(data1):
					SE_set_global_variable_value("sparc_v8_0","tst_b",transform(data1[b-1][1]),4,TY_INT)
					SE_print(data1[b-1][1])
					b += 1
				else:
					pass
		def read_tstc(data):
			global i
			list_resulet=[]
			if i==0:
				i+=1
			else:
				if i <= len(data1):
					tst_a=SE_get_global_variable_value("sparc_v8_0","tst_a",4,TY_INT)
					tst_b=SE_get_global_variable_value("sparc_v8_0","tst_b",4,TY_INT)
					tst_c=SE_get_global_variable_value("sparc_v8_0","tst_c",4,TY_INT)
					print("variable_c:is {}".format(tst_c))
					# print(transform(tst_c))
					# print(transform(data1[i-1][2]))
					if assertequal(transform(tst_c),data1[i-1][2]):
						test_res="Pass"
					else:
						test_res="Fail"
					
					list_resulet="testdata_{},{},{},{},{},{}\n".format(str(i),transform(tst_a),transform(tst_b),transform(tst_c),data1[i-1][2],test_res)

					with open("test_result.txt","a+",encoding="utf-8") as fq:
						fq.write(list_resulet)

					i += 1
				else:
					pass


		ret = SE_set_watch_on_mem("memory_space_0",MO_WRITE,addr_a,OP_WORD_TYPE,10,write_mem_tst_a,i)
		
		ret1 = SE_set_watch_on_mem("memory_space_0",MO_WRITE,addr_b,OP_WORD_TYPE,10,write_mem_tst_b,i)
		
		ret2 = SE_set_watch_on_mem("memory_space_0",MO_WRITE,addr_c,OP_WORD_TYPE,10,read_tstc,None)

	except Exception as ep:
		print(ep)

func()