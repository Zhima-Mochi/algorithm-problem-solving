#
# @lc app=leetcode id=538 lang=python3
#
# [538] Convert BST to Greater Tree
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        st = []
        cur = root
        accum_val = 0
        while True:
            if cur:
                st.append(cur)
                cur = cur.right
            elif len(st):
                st[-1].val += accum_val
                accum_val = st[-1].val
                cur = st[-1].left
                st.pop()
            else:
                break
        return root
# @lc code=end
