#
# @lc app=leetcode id=1720 lang=python3
#
# [1720] Decode XORed Array
#

# @lc code=start
class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        encoded[0] ^= first
        for i in range(1, len(encoded)):
            encoded[i] ^= encoded[i-1]
        encoded.insert(0, first)
        return encoded
# @lc code=end
