/*
 * @lc app=leetcode id=1844 lang=javascript
 *
 * [1844] Replace All Digits with Characters
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
var replaceDigits = function (s) {
    let s_arr = s.toString().split('')
    for (let i in s_arr) {
        if (s_arr[i] >= '0' && s_arr[i] <= '9') {
            s_arr[i] = String.fromCharCode(s_arr[i - 1].charCodeAt(0) + +s_arr[i]);
        }
    }
    return s_arr.join('');
};
// @lc code=end