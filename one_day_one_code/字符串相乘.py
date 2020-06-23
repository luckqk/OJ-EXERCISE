class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
        给定两个以字符串形式表示的非负整数 num1 和 num2，
        返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
        :param num1: 非负整数1
        :param num2: 非负整数2
        :return: 
        """
        if num1 == '0' or num2 == '0':
            return '0'
        #暂定num1被乘数, num2 乘数
        num2 = num2[::-1]
        ans = ''

        for i, curt_num in enumerate(num2):
            curt_sum = self.calCurtSumStr(num1, int(curt_num)) + '0'*i
            ans  = self.calTwoStrSum(ans, curt_sum)

        return ans

    def calCurtSumStr(self, str_num, i_num):
        """
        计算字符串与单一字符的乘积
        :param str_num: 输入字符串，高位在前
        :param i_num: 输入字符
        :return: 字符串形式的乘积结果值，高位在前
        """
        str_reverse = str_num[::-1]
        untreat_list = []

        for i, char in enumerate(str_reverse):
            untreat_list.append(i_num * int(char))

        treat_list = self.treatCarry(untreat_list)
        treat_list = treat_list[::-1]

        return "".join(str(x) for x in treat_list)


    def treatCarry(self, list):
        """
        处理列表进位的问题
        :param list: 待处理的列表
        :return: 处理完成的列表
        """
        carry = 0
        for i, num in enumerate(list):
            carry, list[i] = divmod(num + carry, 10)

        while carry != 0:
            list.append(carry % 10)
            carry //= 10
        return list

    def calTwoStrSum(self, s1, s2):
        """
        计算两个字符串的值
        :param s1: 
        :param s2: 
        :return: 
        """
        if len(s2) > len(s1):
            s1, s2 = s2, s1
        l1 = [int(x) for x in s1]
        l2 = [int(x) for x in s2]

        l1, l2  = l1[::-1], l2[::-1]
        for i in range(0, len(l2), 1):
            l1[i] += l2[i]

        l1 = self.treatCarry(l1)
        l1 = l1[::-1]
        return "".join(str(x) for x in l1)

def main():
    num1 = "788"
    num2 = "9"
    ans = Solution().multiply(num1, num2)
    print(ans)

if __name__ == '__main__':
    main()
