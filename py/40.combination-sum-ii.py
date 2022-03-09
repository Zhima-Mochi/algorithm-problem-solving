#
# @lc app=leetcode id=40 lang=python3
#
# [40] Combination Sum II
#
from typing import *
# @lc code=start


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        width = len(candidates)
        pos_vec = [0]
        sum = 0
        res = []
        while True:
            if pos_vec[-1] != width:
                if sum+candidates[pos_vec[-1]] == target:
                    res.append([candidates[i] for i in pos_vec])
                elif sum+candidates[pos_vec[-1]] < target:
                    sum += candidates[pos_vec[-1]]
                    pos_vec.append(pos_vec[-1]+1)
                    continue
            if pos_vec[-1] == width or sum+candidates[pos_vec[-1]] >= target:
                pos_vec.pop()
                if len(pos_vec) == 0:
                    break
                sum -= candidates[pos_vec[-1]]
                pos_vec[-1] += 1
                while pos_vec[-1] != width and candidates[pos_vec[-1]] == candidates[pos_vec[-1]-1]:
                    pos_vec[-1] += 1
        return res
# @lc code=end
