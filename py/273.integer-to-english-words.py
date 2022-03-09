#
# @lc app=leetcode id=273 lang=python3
#
# [273] Integer to English Words
#

# @lc code=start
class Solution:
    unit_digit = ["Zero", "One", "Two", "Three",
                  "Four", "Five", "Six", "Seven", "Eight", "Nine"]
    ten_digit = ["Twenty", "Thirty", "Forty", "Fifty",
                 "Sixty", "Seventy", "Eighty", "Ninety"]
    two_digit = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]

    def numberToWords(self, num: int) -> str:
        res = str()
        if num == 0:
            return "Zero"

        elif num < 100:
            if num >= 20:
                res = self.ten_digit[num // 10 - 2] + " " + \
                    (self.unit_digit[num % 10] + " " if num % 10 else "")
                return res[0:-1]
            elif num >= 10:
                return self.two_digit[num - 10]
            else:
                return self.unit_digit[num]
        billion_num = num // 1000000000
        num %= 1000000000
        million_num = num // 1000000
        num %= 1000000
        thousand_num = num // 1000
        num %= 1000
        hundred_num = num // 100
        num %= 100
        res = ("" if billion_num == 0 else self.numberToWords(billion_num) + " Billion ") + (""if million_num == 0 else self.numberToWords(million_num) + " Million ") + \
            ("" if thousand_num == 0 else self.numberToWords(thousand_num) + " Thousand ") + ("" if hundred_num == 0 else self.numberToWords(hundred_num) + " Hundred ") + \
            ("" if num == 0 else self.numberToWords(num) + " ")
        return res[0:-1]
# @lc code=end
