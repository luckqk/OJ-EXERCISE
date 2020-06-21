#coding=utf-8
"""
定义一个学生类。有下面的类属性：

1 姓名
2 年龄
3 成绩（语文，数学，英语)[每课成绩的类型为整数]
"""
class student(object):
    name = ''
    age = 0
    score = [0, 0, 0]

    def get_name(self):
        return self.name

    def get_age(self):
        return self.age

    def get_course(self):
        return max(self.score)

    def __init__(self, p_name, p_age, p_score):
        self.name = p_name
        self.age = p_age
        self.score = p_score


def main():
    stu1 = student('QK',27,[40,29,58])
    print(stu1.get_course())

if __name__ == '__main__':
    main()