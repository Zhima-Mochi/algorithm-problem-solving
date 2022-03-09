#
# @lc app=leetcode id=622 lang=python3
#
# [622] Design Circular Queue
#
from typing import *
# @lc code=start


class MyCircularQueue:

    def __init__(self, k: int):
        self.circular_queue = [None]*k
        self.tail = 0
        self.head = 0
        self.num = 0
        self.cap = k

    def enQueue(self, value: int) -> bool:
        if self.num == 0:
            self.num += 1
            self.circular_queue[self.tail] = value
            return True
        elif self.num == self.cap:
            return False
        else:
            self.num += 1
            self.tail = (self.tail+1) % self.cap
            self.circular_queue[self.tail] = value
            return True

    def deQueue(self) -> bool:
        if self.num == 0:
            return False
        elif self.num == 1:
            self.num = 0
            return True
        else:
            self.num -= 1
            self.head = (self.head+1) % self.cap
            return True

    def Front(self) -> int:
        if self.num == 0:
            return -1
        else:
            return self.circular_queue[self.head]

    def Rear(self) -> int:
        if self.num == 0:
            return -1
        else:
            return self.circular_queue[self.tail]

    def isEmpty(self) -> bool:
        return self.num == 0

    def isFull(self) -> bool:
        return self.num == self.cap

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
# @lc code=end
