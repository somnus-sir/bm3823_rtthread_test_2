import os
import json
import chardet
import typing as t

def get_json_from_chip(chip):
    return os.getenv("SKYEYEBIN") + "/coverage_board/" + chip + "/" + chip + ".json"

def get_skyeye_file_from_chip(chip):
    return os.getenv("SKYEYEBIN") + "/coverage_board/" + chip + "/" + chip + ".skyeye"

def get_cpu_name_from_json(json_path):
    with open(json_path ,'r',encoding='utf8')as fp:
        root = json.load(fp)
        for machname, mach in root.items():
            for devicename, device in mach.items():
                if devicename == "class" or devicename == "base":
                    continue
                for attr, value in device.items():
                    if attr == "base" and value == "cpu":
                        return devicename

# 获取文件编码类型
def get_encoding(file):
    # 二进制方式读取，获取字节数据，检测类型
    with open(file, 'rb') as f:
        data = f.read()
        return chardet.detect(data)['encoding']

from chardet.universaldetector import UniversalDetector

file_path = []

def get_encode_info(file):
    with open(file, 'rb') as f:
        detector = UniversalDetector()
        for line in f.readlines():
            detector.feed(line)
            if detector.done:
                break
    detector.close()
    return detector.result['encoding']

def read_file(file):
    with open(file, 'rb') as f:
        return f.read()

def write_file(content, file):
    with open(file, 'wb') as f:
        f.write(content)

def convert_encode2utf8(file, original_encode, des_encode):
    file_content = read_file(file)
    file_decode = file_content.decode(original_encode,'ignore')
    file_encode = file_decode.encode(des_encode)
    write_file(file_encode, file)

def change_file_coding(filename):
    if filename in file_path:
        return
    encode_info = get_encode_info(filename)
    if encode_info != 'g':
        convert_encode2utf8(filename, encode_info, 'gbk')
    encode_info = get_encode_info(filename)
    file_path.append(filename)

def map_byte_to_codepoint_offset(text, encoding, byte_offsets) -> t.Dict[int, int]:
    mapping = {}
    byte_offset = 0
    for codepoint_offset, character in enumerate(text):
        if byte_offset in byte_offsets:
            mapping[byte_offset] = codepoint_offset
        byte_offset += len(character.encode(encoding))
    return mapping

def get_str_from_offset(file_path, offset, length):
    f = open(file_path, "r", encoding="utf-8")
    f.seek(offset)
    str = f.read(length)
    #print(str)
    return str

def get_all_dirs(path):
    dirs = []
    flist = os.listdir(path)
    for f in flist:
        sub_path = os.path.join(path, f)
        if os.path.isdir(sub_path):
            dirs.append(sub_path)
            dirs.extend(get_all_dirs(sub_path))
    return dirs

if __name__ == '__main__':
    # cpu_name = get_cpu_name_from_json('./coverage_board/mpc755/mpc755.json')
    # print(cpu_name)
    # json_path = get_json_from_chip('mpc755')
    # cpu_name = get_cpu_name_from_json(json_path)
    # print(json_path)
    # print(cpu_name)
    # get_str_from_offset('./test/source/kmp.c',84,16)
    change_file_coding("fun.py")
