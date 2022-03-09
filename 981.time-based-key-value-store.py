#
# @lc app=leetcode id=981 lang=python3
#
# [981] Time Based Key-Value Store
#
from collections import defaultdict
from bisect import bisect_right
# @lc code=start


class TimeMap:

    def __init__(self):
        self.key_time_value = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.key_time_value[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if not key in self.key_time_value:
            return ""
        time_value = self.key_time_value[key]
        res = bisect_right(time_value, (timestamp, chr(127)))
        if res == 0:
            return ""
        else:
            return time_value[res-1][1]
# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
# @lc code=end
