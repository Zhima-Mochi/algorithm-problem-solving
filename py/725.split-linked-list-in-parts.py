#
# @lc app=leetcode id=725 lang=python3
#
# [725] Split Linked List in Parts
#
from typing import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        res = []
        count = 0
        cur = head
        while cur:
            count += 1
            cur = cur.next
        group_size = count//k
        rest = count % k
        cur=head
        while cur:
            res.append(cur)
            for i in range(group_size-1):
                cur = cur.next
            if group_size > 0 and rest > 0:
                cur = cur.next
                rest -= 1
            next_cur = cur.next
            cur.next = None
            cur = next_cur
        for i in range(len(res), k):
            res.append(None)
        return res
# @lc code=end
