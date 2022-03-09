#
# @lc app=leetcode id=971 lang=python3
#
# [971] Flip Binary Tree To Match Preorder Traversal
#
from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left: Optional[TreeNode] = left
        self.right: Optional[TreeNode] = right
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def flipMatchVoyage(self, root: Optional[TreeNode], voyage: List[int]) -> List[int]:
        res = []
        st: List[TreeNode] = []
        cur = root
        if cur.val != voyage[0]:
            return [-1]
        voyage_idx = 1
        while cur or len(st):
            if cur:
                if cur.right and cur.right.val == voyage[voyage_idx]:
                    cur.left, cur.right = cur.right, cur.left
                    if cur.right:
                        res.append(cur.val)
                    voyage_idx += 1
                elif cur.left and cur.left.val != voyage[voyage_idx]:
                    return [-1]
                elif cur.left:
                    voyage_idx += 1
                st.append(cur)
                cur = cur.left
            else:
                cur = st.pop().right
                if cur and cur.val != voyage[voyage_idx]:
                    return [-1]
                if cur:
                    voyage_idx += 1
        return res


# @lc code=end
