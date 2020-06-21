class Solution:
    def addBinary(self, a: str, b: str) -> str:
        """
        你两个二进制字符串，返回它们的和（用二进制表示）。
        输入为 非空 字符串且只包含数字 1 和 0。
        :param a: 字符串1
        :param b: 字符串2
        :return: 结果
        """
        interval = max(-len(a) - 1, -len(b) - 1)
        add_num = 0
        ans = ''
        for i in range(-1, interval, -1):
            temp_sum = int(a[i]) + int(b[i]) + add_num
            add_num = temp_sum // 2
            ans  = str(temp_sum % 2) + ans

        if interval > -len(a) - 1:
            for i in range(interval, -len(a) - 1, -1):
                temp_sum = int(a[i]) + add_num
                add_num = temp_sum // 2
                ans = str(temp_sum % 2) + ans

        if interval > - len(b) - 1:
            for i in range(interval, -len(b) - 1, -1):
                temp_sum = int(b[i]) + add_num
                add_num = temp_sum // 2
                ans = str(temp_sum % 2) + ans

        if add_num != 0:
            ans  = '1' + ans

        return ans

#官方答案1
class Solution2:
    def addBinary(self, a, b) -> str:
        """
        使用python格式化format函数，对于超长的a，b不适用
        :param a: 
        :param b: 
        :return: 
        """
        return '{0:b}'.format(int(a, 2) + int(b, 2))

#官方答案2
class Solution3:
    def addBinary(self, a, b) -> str:
        """
        逐位相加，和我的想法一样，但利用好了python函数更为精简，
        少了多次转换
        :param a: 
        :param b: 
        :return: 
        """

        class Solution:
            def addBinary(self, a, b) -> str:
                n = max(len(a), len(b))
                #zfill这个函数非常重要
                a, b = a.zfill(n), b.zfill(n)

                carry = 0
                answer = []
                for i in range(n - 1, -1, -1):
                    if a[i] == '1':
                        carry += 1
                    if b[i] == '1':
                        carry += 1

                    if carry % 2 == 1:
                        answer.append('1')
                    else:
                        answer.append('0')

                    carry //= 2

                if carry == 1:
                    answer.append('1')
                answer.reverse()

                return ''.join(answer)

#官方答案3
class Solution4:
    def addBinary(self, a, b) -> str:
        """
        位运算解题，同样的因为要转换为int型
        不适用于极大数
        :param a: 
        :param b: 
        :return: 
        """
        x, y = int(a, 2), int(b, 2)
        #把 a和 b 转换成整型数字 x 和 y，x 保存结果，y 保存进位
        #不断相加直到进位y为0
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        #bin()返回的是0bXXXX，所以还要使用切片[2:]
        return bin(x)[2:]


def main():
    num  = Solution().addBinary('1010','1011')
    print(num)
    assert num == '10101'


if __name__ == '__main__':
    main()