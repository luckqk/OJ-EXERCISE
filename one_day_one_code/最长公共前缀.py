from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        """
        编写一个函数来查找字符串数组中的最长公共前缀。
        如果不存在公共前缀，返回空字符串 ""。
        
        本方法比较为两个比较，还有另一种统一比较所有串的某一位
        :param strs: 字符串数组
        :return: 公共前缀
        """
        if len(strs) == 0:
            return  ""
        ans = strs[0]

        for i, str in enumerate(strs):
            ans = self.getCommonPrefix(ans, strs[i])
            if ans == "":
                break

        return ans

    def getCommonPrefix(self, str1, str2):
        min_len = min(len(str1), len(str2))
        s_ans = ""

        for i in range(0, min_len, 1):
            if str1[i] == str2[i]:
                s_ans += str1[i]
            else:
                break

        return s_ans

    #官方getCommonPrefix写法，利用切片
    def lcp(self, str1, str2):
        length, index = min(len(str1), len(str2)), 0
        while index < length and str1[index] == str2[index]:
            index += 1
        return str1[:index]


def main():
    ans = Solution().longestCommonPrefix(["dog","racecar","car"])
    print(ans)

if __name__ == '__main__':
    main()
