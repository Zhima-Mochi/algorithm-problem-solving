#
# @lc app=leetcode id=2196 lang=python3
#
# [2196] Create Binary Tree From Descriptions
#
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

# t:O(n), s:O(n)
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        memo = dict()
        for desc in descriptions:
            par = desc[0]
            ch = desc[1]
            isLeft = desc[2] == 1
            if par not in memo:
                memo[par] = TreeNode(par)
            if ch not in memo:
                memo[ch] = TreeNode(ch)
            if isLeft:
                memo[par].left = memo[ch]
            else:
                memo[par].right = memo[ch]
        rootSet = set(memo.keys())
        for node in memo.values():
            if node.left:
                rootSet.remove(node.left.val)
            if node.right:
                rootSet.remove(node.right.val)
        return memo[rootSet.pop()]
# @lc code=end
