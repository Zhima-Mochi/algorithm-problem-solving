#
# @lc app=leetcode id=301 lang=python3
#
# [301] Remove Invalid Parentheses
#
from typing import *
# @lc code=start


class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        width = len(s)
        removed_min_left = 0
        removed_min_right = 0
        for c in s:
            if c == '(':
                removed_min_left += 1
            elif c == ')':
                if removed_min_left > 0:
                    removed_min_left -= 1
                else:
                    removed_min_right += 1

        def valid_check(s):
            balance_count = 0
            for c in s:
                if c == '(':
                    balance_count += 1
                elif c == ')':
                    balance_count -= 1
                    if balance_count < 0:
                        return False
            return balance_count == 0
        res = []

        def dfs(s, pos, current_word: str, current_balance, removed_min_left, removed_min_right):
            if current_balance < 0:
                return
            if removed_min_left == 0 and removed_min_right == 0:
                current_word += s[pos:]
                if valid_check(current_word):
                    res.append(current_word)
                return
            if width-pos < removed_min_left+removed_min_right:
                return
            while pos != width and s[pos] != '(' and s[pos] != ')':
                current_word += s[pos]
                pos += 1
            if pos == width:
                return
            if s[pos] == '(' and removed_min_left > 0:
                dfs(s, pos+1, current_word, current_balance,
                    removed_min_left-1, removed_min_right)
            elif s[pos] == ')' and removed_min_right > 0:
                dfs(s, pos+1, current_word, current_balance,
                    removed_min_left, removed_min_right-1)
            current_word += s[pos]
            if s[pos] == '(':
                current_balance += 1
            else:
                current_balance -= 1
            pos += 1
            while pos != width and s[pos] == s[pos-1]:
                current_word += s[pos]
                if s[pos] == '(':
                    current_balance += 1
                else:
                    current_balance -= 1
                pos += 1
            dfs(s, pos, current_word, current_balance,
                removed_min_left, removed_min_right)
        dfs(s, 0, "", 0, removed_min_left, removed_min_right)
        return res

# @lc code=end
