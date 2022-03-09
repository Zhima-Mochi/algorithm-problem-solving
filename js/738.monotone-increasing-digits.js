/*
 * @lc app=leetcode id=738 lang=javascript
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var monotoneIncreasingDigits = function (n) {
    const n_arr = n.toString().split('').map(v => +v);
    let i = 1;
    while (i < n_arr.length && n_arr[i] >= n_arr[i - 1]) {
        ++i;
    }
    while (i > 0 && n_arr[i - 1] > n_arr[i]) {
        n_arr[i - 1] -= 1;
        --i;
    }
    for (i += 1; i < n_arr.length; ++i) {
        n_arr[i] = 9;
    }
    return parseInt(n_arr.join(''));
};
// @lc code=end