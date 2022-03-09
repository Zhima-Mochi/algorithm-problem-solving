#
# @lc app=leetcode id=816 lang=python3
#
# [816] Ambiguous Coordinates
#
import itertools
# @lc code=start


class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        def generate_valid(s):
            width = len(s)
            for pos in range(1, width+1):
                left = s[:pos]
                right = s[pos:]
                if (not left[0] == '0' or left == '0') and (not right.endswith('0')):
                    yield left+('.' if pos != width else '')+right
        s = s[1:-1]
        return [f"({a}, {b})" for i in range(1, len(s)) for a, b in itertools.product(generate_valid(s[:i]), generate_valid(s[i:]))]
# @lc code=end
