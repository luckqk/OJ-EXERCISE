# coding=utf-8
import urllib.request
import os
import random


def get_num(num):
    """
    判断列表里面的元素为数字类型。其他类型则报错，并且返回一个偶数列表
    :param num: 列表类型
    :return:
    """
    num_ret = []
    if not isinstance(num, list):
        return "输入参数非列表"
    for point in num:
        if not isinstance(point, int):
            return str(point) + "不是数字类型！"
        else:
            if point % 2 == 0:
                num_ret.append(point)
    return num_ret


def get_page(url):
    """
    返回网页的内容
    :param url: 需要获取网页内容的网址
    :return:
    """
    response = urllib.request.urlopen(url)
    html_content = response.read().decode('utf-8')
    return html_content


def save_url_content(url, folder_path=None):
    """
    打开网页并以随机文件名保存网页内容至特定地址
    :param url: 网页网址
    :param folder_path: 特定地址
    :return: 
    """
    try:
        d = urllib.request.urlopen(url)
    except Exception as e:
        return u"该网页无法打开"
    else:
        content = d.read()
    if not os.path.isdir(folder_path):
        return u"文件夹路径非法"
    else:
        rand_filename = random.randint(1, 1000)
        file_path = os.path.join(folder_path, rand_filename)
        d = open(file_path, 'w')
        d.write(content)
        d.close()
        return file_path


def get_dir(f):
    """
    返回路径下的所有文件夹组成的列表
    :param f: 任意一个磁盘路径
    :return:
    """
    l_dir = []
    if not os.path.isdir(f):
        return "非法路径"

    """
    os中的walk()函数可以遍历文件夹下所有的文件
    dirpath：string，代表目录的路径
    dirnames：list，包含了当前dirpath路径下所有的子目录名字（不包含目录路径）
    filenames：list，包含了当前dirpath路径下所有的非目录子文件的名字（不包含目录路径）
    """
    # for root, dirs, files in os.walk(f):
    #     l_dir.append(dirs)

    """
    os中listdir()只遍历当前文件夹下的所有文件
    """
    for content in os.listdir(f):
        if os.path.isdir(os.sep.join([f, content])):
            l_dir.append(content)

    if l_dir == []:
        return "No dir"
    else:
        return l_dir


def main():
    ans1 = get_num([1, 4, 6, 3, 7, 2, 786, 31])
    # assert ans1 == [4,6,2,786]
    # print(get_page("https://www.baidu.com"))
    file_content = get_dir(os.sep.join(['E:', '钱坤', '练习', 'python']))
    print(file_content)


if __name__ == '__main__':
    main()
