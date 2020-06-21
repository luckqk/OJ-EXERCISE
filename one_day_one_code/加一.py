#coding= utf-8
class Solution:
    def plusOne(self, digits):
        digits[-1] += 1
        for i in range(len(digits)-1, 0, -1):
            if digits[i] >= 10:
                digits[i - 1] += 1
                digits[i] %= 10

        if digits[0] >= 10:
            digits[0] %= 10
            new_digits = [1] + digits
            return new_digits
        else:
            return digits



def main():
    ans = Solution().plusOne([9,9,9])
    print(ans)

if __name__ == '__main__':
    main()