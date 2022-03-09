#
# @lc app=leetcode id=1528 lang=python3
#
# [1528] Shuffle String
#

# @lc code=start
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        width = len(s)
        s_ls = list(s)
        pos = 0
        while pos < width:
            if indices[pos] == pos:
                pos += 1
            else:
                s_ls[pos], s_ls[indices[pos]] = s_ls[indices[pos]], s_ls[pos]
                swap_pos = indices[pos]
                indices[pos], indices[swap_pos] = indices[swap_pos], indices[pos]
        return "".join(s_ls)
# @lc code=end
