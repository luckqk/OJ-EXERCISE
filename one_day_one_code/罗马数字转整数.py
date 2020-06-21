# 字符          数值
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000

class Solution:
    def romanToInt(self, s: str) -> int:
        dictRoman = {'I':1, 'V':5, 'X':10, 'L':50,
                     'C':100, 'D':500, 'M':1000}
        sumNum = 0
        pt = 0

        while pt < len(s):
            if pt+1 < len(s) and dictRoman[s[pt]] < dictRoman[s[pt+1]]:
                num = self.countNum(pt, s)
                sumNum += num
                pt += 2
            else:
                sumNum += dictRoman[s[pt]]
                pt += 1

        return sumNum


    def countNum(self, curtPt, s):
        if s[curtPt] == 'I':
            if s[curtPt + 1] == 'V':
                return 4
            if s[curtPt + 1] == 'X':
                return 9
        elif s[curtPt] == 'X':
            if s[curtPt + 1] == 'L':
                return 40
            if s[curtPt + 1] == 'C':
                return 90
        elif s[curtPt] == 'C':
            if s[curtPt + 1] == 'D':
                return 400
            if s[curtPt + 1] == 'M':
                return 900
        else:
            return 0


class Solution2(object):
    def romanToInt(self, x):
        """
        本质是当前一位小于后一位时，对前一位是减法处理，当前一位大于后一位时，是加法处理
        :type s: str
        :rtype: int
        """
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        num = 0
        for i in range(len(x) - 1):
            num1 = d[x[i]]
            num2 = d[x[i + 1]]

            if num1 >= num2:
                num += num1

            else:
                num -= num1

        num += d[x[-1]]

        return num

def main():
    ans = Solution().romanToInt('MCMXCIV')
    print(ans)

if __name__ == '__main__':
    main()