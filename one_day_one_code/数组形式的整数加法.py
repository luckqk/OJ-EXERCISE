from typing import List

class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        """
        对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
        例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
        给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
        :param A: 
        :param K: 
        :return: 
        """
        add_pt = 0
        ans = []
        i = -1
        while add_pt != 0 or K > 0 or i > -len(A) - 1:
            if i > -len(A) - 1:
                curt_pt = A[i] + K % 10 + add_pt
            else:
                curt_pt = K % 10 + add_pt
            add_pt, curt_num = divmod(curt_pt, 10)
            # curt_num = curt_pt % 10
            # add_pt = curt_pt // 10
            ans.append(curt_num)
            K = K // 10
            i -= 1

        ans.reverse()
        return ans


class Solution2:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        """
        官方解法区别在于carry值一下将整个K考虑进去
        :param A: 
        :param K: 
        :return: 
        """
        A[-1] += K
        for i in range(len(A) - 1, -1, -1):
            carry, A[i] = divmod(A[i], 10)
            if i:
                A[i - 1] += carry
        if carry:
            A = map(int, str(carry)) + A
        return A


def main():
    ans = Solution().addToArrayForm([2], 998)
    print(ans)
    pass


if __name__ == '__main__':
    main()
