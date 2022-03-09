#
# @lc app=leetcode id=655 lang=python3
#
# [655] Print Binary Tree
#
from typing import *


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


class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        def find_height(node: TreeNode):
            if not node:
                return -1
            return 1+max(find_height(node.left), find_height(node.right))

        height = find_height(root)
        n = pow(2, height+1)-1
        res = [[""]*n for _ in range(height+1)]

        def preorder_trasversal(res, node, depth, pos):
            if not node:
                return
            res[depth][pos] = str(node.val)
            preorder_trasversal(res, node.left, depth+1,
                                pos-pow(2, height-depth-1))
            preorder_trasversal(res, node.right, depth+1,
                                pos+pow(2, height-depth-1))
        preorder_trasversal(res, root, 0, (n-1)//2)
        return res


# @lc code=end
