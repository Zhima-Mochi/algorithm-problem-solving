#
# @lc app=leetcode id=1952 lang=python3
#
# [1952] Three Divisors
#

# @lc code=start
class Solution:
    def isThree(self, n: int) -> bool:
        if n <= 3:
            return False
        else:
            val = round(pow(n, 0.5))

            def isPrime(n):
                if n == 1:
                    return False
                if n == 2:
                    return True
                if n % 2 == 0:
                    return False
                for i in range(3, round(pow(n, 0.5))+1, 2):
                    if n % i == 0:
                        return False
                return True

            if val*val == n and isPrime(val):
                return True
        return False
# @lc code=end
