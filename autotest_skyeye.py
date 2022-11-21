# coding:utf-8

import getopt
import os
import platform
import psutil
import sys
from pathlib import Path

testcase_branch = "new_framework"  # skyeye code branch
testcase_dir = "."                 # change it to your testcase directory or simply pass argument to override it, eg "python autotest_skyeye.py arm_testcase"
skyeye_bin = r"C:\SkyEye\opt\skyeye\bin\skyeye"              # the skyeye executable program
log_path = "."


def set_path():
	global testcase_dir
	global skyeye_bin
	global log_path

	# parse options
	opts, args = getopt.getopt(sys.argv[1:], "", [])
	if len(args) < 2:
		if args:
			testcase_dir = args[0]
	else:
		raise Exception("Too many arguments.")

	# check exist
	testcase_dir = os.path.abspath(testcase_dir)
	if not Path(testcase_dir).is_dir():
		raise Exception("Path does not exist.")
	# set by system
	'''if platform.system() == "Windows":
		if os.getenv("SKYEYEBIN") == None:
			raise Exception("Environment varible SKYEYEBIN does not exist.")
		log_path = os.path.abspath(os.getenv("SKYEYEBIN"))
		skyeye_bin = os.path.join(log_path, "skyeye.exe")
	else:
		log_path = os.getenv("HOME") + "/.skyeye/"
		skyeye_bin = "/opt/skyeye/bin/skyeye"
	'''

def change_dir(arg):
	os.chdir(arg)
	print("\nCurrent directory path: " + arg)


def kill_process(process_name):
	if platform.system() == "Linux":
		for p in psutil.process_iter():
			if p.name() == process_name:
				p.kill()


class test_main():
	def __init__(self):
		self.test_dir_list = []
		self.root_dir = os.getcwd()
		fp = open(os.path.join(log_path, 'test.log'), 'w')
		fp.close()

	def find_all_testcase(self):
		for dirpath, dirnames, filenames in os.walk(testcase_dir):
			if "skyeye_test.py" in filenames or "skyeye_test.pyc" in filenames:
				for filename in filenames:
					if filename.endswith(".skyeye"):
						self.test_dir_list.append(os.path.join(dirpath, filename))
		if len(self.test_dir_list) == 0:
			raise Exception("No testcase detected.")

	def run_test(self):
		self.write_branch()
		for test_dir in self.test_dir_list:
			test_info = os.path.split(os.path.normpath(os.path.join(self.root_dir, test_dir)))
			change_dir(test_info[0])
			print("%d / %d" % (self.test_dir_list.index(test_dir) + 1, len(self.test_dir_list)))
			os.system(skyeye_bin + " -a")
			#kill_process("putty")
		self.del_branch()

	def write_branch(self):
		wb = open(os.path.join(log_path, 'branch_info.txt'), 'w')
		wb.write(testcase_branch)
		wb.close()

	def del_branch(self):
		if os.path.isfile(os.path.join(log_path, 'branch_info.txt')):
			os.remove(os.path.join(log_path, 'branch_info.txt'))

	def print_test_log(self):
		temp = {}
		collapsed_list = []
		pass_list = []
		error_list = []
		skip_list = []
		skip_info = ["Different branches to skip", "The test is not enabled",
					 "This is a Linux use cases", "This is a Windows use cases",
					 "run_system parameter error"]
		fp = open(os.path.join(log_path, 'test.log'), 'r')
		test_log = fp.readlines()
		fp.close()
		for log in test_log:
			temp_li = []
			log_li = log.strip("\n").split("->")
			if log_li[0] not in temp.keys():
				temp[log_li[0]] = []
			for log_info in log_li:
				temp_li.append(log_info)
			temp[log_li[0]].append(temp_li)
		for test_dir in self.test_dir_list:
			if test_dir in temp.keys():
				for info in temp[test_dir]:
					if info[1] == "The test pass":
						pass_list.append(info)
					elif info[1] in skip_info:
						skip_list.append(info)
					else:
						error_list.append(info)
			else:
				collapsed_list.append(test_dir)
		dir_len = len(os.path.commonprefix(self.test_dir_list))
		if dir_len > len(testcase_dir):
			dir_len = len(testcase_dir) + 1
		print("\nThe test results (%s):" % testcase_dir)
		if len(error_list) > 0:
			count = 1
			print("  ERROR:")
			for error in error_list:
				print("    %d.%s--->%s, Run_mode: %s" % (count, error[0][dir_len:], error[1], error[3]), end=', ')
				if error[4] != "None":
					print("Leak_mem: %s MB" % error[4])
				else:
					print("")
				count += 1
		if len(collapsed_list) > 0:
			count = 1
			print("  COLLAPSED:")
			for coll in collapsed_list:
				print("    %d.%s--->SkyEye collapsed!!!!" % (count, coll[dir_len:]))
				count += 1
		if len(skip_list) > 0:
			count = 1
			print("  SKIP:")
			for skip in skip_list:
				print("    %d.%s--->%s" % (count, skip[0][dir_len:], skip[1]))
				count += 1
		if len(pass_list) > 0:
			count = 1
			print("  PASS:")
			for pa in pass_list:
				print("    %d.%s--->%s, Speed: %s, Run_mode: %s" % (count, pa[0][dir_len:], pa[1], pa[2], pa[3]), end=', ')
				if pa[4] != "None":
					print("Leak_mem: %s MB" % pa[4])
				else:
					print("")
				count += 1


if __name__ == '__main__':

	try:
		print(os.getenv("SKYEYEBIN"))
		set_path()
		tm = test_main()
		tm.find_all_testcase()
		tm.run_test()
		tm.print_test_log()

	except Exception as e:
		print('Error:', e)
		print("Usage: " + sys.argv[0] + " [directory]")

	except KeyboardInterrupt:
		print("Autotest canceled by user.")
		exit(1)
