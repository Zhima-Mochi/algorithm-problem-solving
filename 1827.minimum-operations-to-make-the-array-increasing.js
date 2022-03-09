/*
 * @lc app=leetcode id=1827 lang=javascript
 *
 * [1827] Minimum Operations to Make the Array Increasing
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
var minOperations = function (nums) {
    let res = 0;
    let prev = 0;
    for (n of nums) {
        if (n > prev) {
            prev = n;
        } else {
            res += prev - n + 1;
            ++prev;
        }
    }
    return res;
};
// @lc code=end