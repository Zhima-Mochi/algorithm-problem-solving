#
# @lc app=leetcode id=1475 lang=python3
#
# [1475] Final Prices With a Special Discount in a Shop
#

# @lc code=start
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        st = []
        width = len(prices)
        for i in range(width):
            while len(st) and prices[st[-1]] >= prices[i]:
                prices[st[-1]] -= prices[i]
                st.pop()
            st.append(i)
        return prices
# @lc code=end
