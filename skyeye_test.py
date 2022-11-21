#coding:utf-8
import time
import os
import sys
from skyeye_autotest_command import *

class test():
	def __init__(self):
		testname="bm3823_rtthread_test_2.skyeye"
		test_branch='new_framework'
		enable=True
		run_system="all"
		self.ac=autotest_command(testname,enable,run_system,test_branch)

	def dev_init(self):
		self.ac.add_file_out_dev('bm3823_system_control_0','log.txt')

	def test_flow(self):
		self.ac.run_script()
		self.dev_init()
		self.ac.run(5)
		# self.ac.stop()
		# self.ac.compare("log.txt",self.expect()[0],100)
		# self.ac.reset()
		# self.ac.output_result()
	def test_main(self):
		self.test_flow()
	def expect(self):
		expected_output=['''
		
 \ | /
- RT -     Thread Operating System
 / | \     4.0.3 build Mar  9 2021
 2006 - 2020 Copyright by rt-thread team
sparc v8 hello rt-thread!
msh />

'''
]
		return expected_output