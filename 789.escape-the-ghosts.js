/*
 * @lc app=leetcode id=789 lang=javascript
 *
 * [789] Escape The Ghosts
 */

// @lc code=start
/**
 * @param {number[][]} ghosts
 * @param {number[]} target
 * @return {boolean}
 */
var escapeGhosts = function (ghosts, target) {
    const distance = Math.abs(target[0]) + Math.abs(target[1]);
    return ghosts.findIndex(ghost => Math.abs(ghost[0] - target[0]) + Math.abs(ghost[1] - target[1]) <= distance) == -1 ? true : false;
};
// @lc code=end