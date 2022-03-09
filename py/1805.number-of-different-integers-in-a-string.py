#
# @lc app=leetcode id=1805 lang=python3
#
# [1805] Number of Different Integers in a String
#

# @lc code=start
class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        diff_num = set()
        digit_w = []
        for i in range(len(word)):
            if word[i].isdigit():
                digit_w.append(word[i])
            else:
                if digit_w != []:
                    for non_zero_ind in range(len(digit_w)):
                        if digit_w[non_zero_ind] != '0':
                            break
                    diff_num.add(''.join(digit_w[non_zero_ind:]))
                    digit_w.clear()
        if digit_w != []:
            for non_zero_ind in range(len(digit_w)):
                if digit_w[non_zero_ind] != '0':
                    break
            diff_num.add(''.join(digit_w[non_zero_ind:]))
            digit_w.clear()
        return len(diff_num)
# @lc code=end
