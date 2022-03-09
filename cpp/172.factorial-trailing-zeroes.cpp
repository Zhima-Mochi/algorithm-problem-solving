/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        int divisor=5;
        while(n/divisor){
            res+=n/divisor;
            divisor*=5;
        }
        return res;
    }
};
// @lc code=end

