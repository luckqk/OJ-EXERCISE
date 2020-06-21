# coding=UTF-8
import os
import sys
import glob

def get_doc(module):
    """
    返回module的帮助文档
    :param module: 该脚本中导入或定义的模块对象
    :return: 
    """
    __import__(module)
    my_module=sys.modules[module]
    doc=my_module.__doc__
    return doc

def get_text(f):
    """
    返回f文件的内容
    :param f: 任意一个文件的磁盘路径
    :return: 
    """
    if os.path.exists(f):
        my_file = open(f,mode='r')
        content = my_file.read()
        my_file.close()
        return content
    else:
        print("fault path")
        return

def get_dir(folder = None):
    """
    返回folder文件夹的文件列表
    :param folder: 任意一个文件夹
    :return: 
    """
    if folder is not None:
        my_path = "%s\*.*" %folder
        file_name = glob.glob(my_path)
        if file_name == []:
            return "文件不存在"
        else:
            return file_name
    else:
        return "文件夹名非法"


def main():
    content = get_doc('math')
    #注意\\abc中\a需要\来转义
    file_content = get_text('E:\钱坤\练习\python\\abc.txt')
    file_content2 = get_dir('E:\钱坤\练习\python\code_exercise\Day07')
    print(content)
    print(file_content)
    print(file_content2)

if __name__ == '__main__':
    main()