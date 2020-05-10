#方法一 暴力解法
class solution1:
    def reverse(self, x: int):
        """
        将整数中每位上的数字进行反转
        :param x:整数 
        """
        if -10<x<10:
            return x
        str_x = str(x)
        if str_x[0] != "-":
            str_x = str_x[::-1]
            x = int(str_x)
        else:
            str_x = str_x[:0:-1]
            x = int(str_x)
            x = -x
        return x if -2147483648<= x <= 2147483647 else 0

#方法二 提前进行溢出预判
class solution2:
    def reverse(self,x:int):
        bound = (1<<31) - 1 if x > 0 else 1 << 31
        y, res = abs(x),0
        while y != 0:
            res = res * 10 + y % 10
            if res > bound:
                return 0
            y //= 10
        return res if x > 0 else -res

def main():
    a = -1500
    sol = solution2()
    ans = sol.reverse(a)
    print(ans)
    # print(bin(a))
    # print(bin())


if __name__ == '__main__':
    main()
