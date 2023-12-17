#
# @lc app=leetcode id=2276 lang=python3
#
# [2276] Count Integers in Intervals
#

# @lc code=start


class SegmentTree:
    class Node:
        def __init__(self, start, end):
            self.start = start
            self.end = end
            self.total = 0
            self.left = self.right = None

    def __init__(self):
        self.root = self.Node(0, 10**9-1)

    def add(self, start, end, node=None):
        if node is None:
            node = self.root
        if node.total == node.end-node.start+1:
            return node.total
        if node.start == start and node.end == end:
            node.total = node.end-node.start+1
            return node.total
        mid = node.start+(node.end-node.start)//2
        if node.left == None:
            node.left = self.Node(node.start, mid)
        if node.right == None:
            node.right = self.Node(mid+1, node.end)
        if end <= mid:
            node.total = self.add(start, end, node.left)+node.right.total
        elif start >= mid+1:
            node.total = node.left.total + self.add(start, end, node.right)
        else:
            node.total = self.add(start, node.left.end, node.left) + \
                self.add(node.right.start, end, node.right)
        if node.total == node.end-node.start+1:
            node.left = node.right = None
        return node.total


class CountIntervals:

    def __init__(self):
        self.seg = SegmentTree()

    def add(self, left: int, right: int) -> None:
        self.seg.add(left-1, right-1)

    def count(self) -> int:
        return self.seg.root.total


# Your CountIntervals object will be instantiated and called as such:
# obj = CountIntervals()
# obj.add(left,right)
# param_2 = obj.count()
# @lc code=end
