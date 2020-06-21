class Solution:
    def intToRoman(self, num: int) -> str:
        curtDict = {1:'I', 4:'IV', 5:'V', 9:'IX', 10:'X',
                    40:'XL',50:'L',90:'XC', 100:'C',
                    400:'CD', 500:'D', 900:'CM', 1000:'M'}
        baseList = [1000,900,500,400,
                    100,90,50,40,
                    10,9,5,4,1]

        i = 0
        ansStr = ''
        while num > 0:
            times = num // baseList[i]
            for m in range(times):
                ansStr += curtDict[baseList[i]]
            num = num - times * baseList[i]
            i += 1

        return ansStr

#官方solution
digits = [(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"),
          (50, "L"), (40, "XL"), (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")]

def intToRoman(self, num: int) -> str:
    roman_digits = []
    # Loop through each symbol.
    for value, symbol in digits:
        # We don't want to continue looping if we're done.
        if num == 0: break
        count, num = divmod(num, value)
        # Append "count" copies of "symbol" to roman_digits.
        roman_digits.append(symbol * count)
    return "".join(roman_digits)


def main():
    ans = Solution().intToRoman(4)
    print(ans)

if __name__ == '__main__':
    main()