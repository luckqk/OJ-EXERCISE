#转化为字符串以及对折判断都可以避免溢出
class Solution1:
    def isPalindrome(self, x: int) -> bool:
        """
        利用递归验证数字是否是回文数
        :param x: 数字
        """
        def ifFlag(a, flag=True):
            s = str(a)
            if len(s) == 0 or len(s) == 1:
                return flag
            if s[0] == s[-1]:
                return ifFlag(s[1:-1])
            else:
                flag = False
                return flag

        return ifFlag(x)

class Solution2:
    def isPalindrome(self, x: int) -> bool:
        """
        利用list验证数字是否是回文数
        :param x: 数字
        """
        sL = list(str(x))
        while len(sL) > 1:
            if sL.pop(0) != sL.pop():
                return False
        return True

class Solution3:
    def isPalindrome(self, x: int) -> bool:
        """
        对折进行判断
        :param x: 
        """
        if x < 0 or ( x % 10 == 0 and x != 0):
            return False
        inverseNum = 0
        while x > inverseNum:
            inverseNum = inverseNum * 10 + x % 10
            x //= 10
        return x == inverseNum or x == inverseNum // 10


def main():
    ans = Solution3().isPalindrome(121)
    print(ans)

if __name__ == '__main__':
    main()
