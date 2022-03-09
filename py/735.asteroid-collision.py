#
# @lc app=leetcode id=735 lang=python3
#
# [735] Asteroid Collision
#

# @lc code=start
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        aster_stack = []
        for n in asteroids:
            while aster_stack and n < 0 < aster_stack[-1]:
                if aster_stack[-1] < -n:
                    aster_stack.pop()
                elif aster_stack[-1] == -n:
                    aster_stack.pop()
                    break
                else:
                    break
            else:
                aster_stack.append(n)
        return aster_stack
# @lc code=end
