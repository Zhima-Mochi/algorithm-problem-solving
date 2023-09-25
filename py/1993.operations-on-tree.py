#
# @lc app=leetcode id=1993 lang=python3
#
# [1993] Operations on Tree
#

# @lc code=start
class LockingTree:
    lockedChNum = []
    isLockedBy = dict()
    parent = []

    def popup(self, num, val):
        while self.parent[num] != -1:
            self.lockedChNum[self.parent[num]] += val
            num = self.parent[num]

    def isChildOf(self, child, parent):
        while self.parent[child] != -1:
            child = self.parent[child]
            if child == parent:
                return True
        return False

    def isAncestorFree(self, num):
        while self.parent[num] != -1:
            if self.parent[num] in self.isLockedBy:
                return False
            num = self.parent[num]
        return True

    def __init__(self, parent: List[int]):
        self.parent = parent
        self.isLockedBy = dict()
        n = len(parent)
        self.lockedChNum = [0]*n

    def lock(self, num: int, user: int) -> bool:
        if num in self.isLockedBy:
            return False
        self.isLockedBy[num] = user
        self.popup(num, 1)
        return True

    def unlock(self, num: int, user: int) -> bool:
        if num in self.isLockedBy and self.isLockedBy[num] == user:
            self.isLockedBy.pop(num)
            self.popup(num, -1)
            return True
        return False

    def upgrade(self, num: int, user: int) -> bool:
        if self.lockedChNum[num] >= 1 and self.isAncestorFree(num):
            if not self.lock(num, user):
                return False
            for node in list(self.isLockedBy):
                if self.isChildOf(node, num):
                    self.unlock(node, self.isLockedBy[node])
            return True
        return False


# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)
# @lc code=end
