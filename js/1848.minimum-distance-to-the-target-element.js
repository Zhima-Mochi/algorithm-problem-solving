/*
 * @lc app=leetcode id=1848 lang=javascript
 *
 * [1848] Minimum Distance to the Target Element
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @param {number} start
 * @return {number}
 */
var getMinDistance = function (nums, target, start) {
    let res = nums.length;
    for (let i in nums) {
        if (i >= start + res) {
            break;
        }
        if (nums[i] == target) {
            res = Math.min(res, Math.abs(start - i));
        }
    }
    return res;
};
// @lc code=end