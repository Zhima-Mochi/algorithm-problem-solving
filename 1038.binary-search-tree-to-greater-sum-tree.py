#
# @lc app=leetcode id=1038 lang=python3
#
# [1038] Binary Search Tree to Greater Sum Tree
#
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# t:O(N), s:O(N)
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        st: List[TreeNode] = []
        cur = root
        accum_val = 0
        while cur or len(st):
            if cur:
                st.append(cur)
                cur = cur.right
            else:
                st[-1].val += accum_val
                accum_val = st[-1].val
                cur = st.pop().left
        return root
# @lc code=end
