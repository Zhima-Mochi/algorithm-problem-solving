/*
 * @lc app=leetcode id=1941 lang=javascript
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
 */

// @lc code=start
/**
 * @param {string} s
 * @return {boolean}
 */
var areOccurrencesEqual = function (s) {
    let count = {};
    for (let c of s) {
        if (c in count) {
            ++count[c];
        } else {
            count[c] = 1;
        }
    }
    let num = 0;
    return Object.values(count).findIndex(v => {
        if (v > 0) {
            if (num === 0) {
                num = v;
                return false;
            } else if (num !== v) {
                return true;
            }
        }
        return false;
    }) === -1 ? true : false;

};
// @lc code=end