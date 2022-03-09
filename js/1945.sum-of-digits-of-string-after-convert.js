/*
 * @lc app=leetcode id=1945 lang=javascript
 *
 * [1945] Sum of Digits of String After Convert
 */

// @lc code=start
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function (s, k) {
    let res = 0;
    for (let c of s) {
        let val = c.charCodeAt() - 'a'.charCodeAt() + 1;
        res += Math.floor(val / 10) + val % 10;
    }
    while (--k) {
        let next_res = 0;
        while (res) {
            next_res += res % 10;
            res = Math.floor(res / 10);
        }
        res = next_res;
    }
    return res;
};
// @lc code=end