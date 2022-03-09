#
# @lc app=leetcode id=662 lang=python3
#
# [662] Maximum Width of Binary Tree
#
from typing import *
from collections import deque


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
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        node_pos_queue = deque()
        node_pos_queue.append((root, 0))
        res = 0
        while(len(node_pos_queue)):
            q_len = len(node_pos_queue)
            res = max(res, node_pos_queue[-1][1]-node_pos_queue[0][1])
            shift = node_pos_queue[0][1]
            while q_len:
                q_len -= 1
                elem = node_pos_queue.popleft()
                if elem[0].left:
                    node_pos_queue.append((elem[0].left, (elem[1]-shift)*2))
                if elem[0].right:
                    node_pos_queue.append((elem[0].right, (elem[1]-shift)*2+1))
        return res+1
# @lc code=end
