/*
 * @lc app=leetcode id=1961 lang=javascript
 *
 * [1961] Check If String Is a Prefix of Array
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string[]} words
 * @return {boolean}
 */
var isPrefixString = function (s, words) {
    const width = s.length;
    let ind = 0;
    for (let word of words) {
        for (let c of word) {
            if (ind == width || c != s[ind]) {
                return false;
            } else {
                ++ind;
            }
        }
        if (ind == width) {
            return true;
        }
    }
    return false;
};
// @lc code=end