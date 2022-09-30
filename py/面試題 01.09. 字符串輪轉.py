from collections import Counter


class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        return (s1+s1).find(s2) != -1
