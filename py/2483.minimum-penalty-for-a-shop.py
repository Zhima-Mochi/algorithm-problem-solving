#
# @lc app=leetcode id=2483 lang=python3
#
# [2483] Minimum Penalty for a Shop
#

# @lc code=start
class Solution:
    def bestClosingTime(self, customers: str) -> int:
        w = len(customers)
        after_has_cus = customers.count("Y")
        before_has_no_cus = 0
        min_pen = (1 << 31)-1
        res = 0
        for i in range(w):
            pen = before_has_no_cus+after_has_cus
            if pen < min_pen:
                min_pen = pen
                res = i
            if customers[i] == "Y":
                after_has_cus -= 1
            else:
                before_has_no_cus += 1
        pen = before_has_no_cus+after_has_cus
        if pen < min_pen:
            return w
        return res

# @lc code=end
