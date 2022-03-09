/*
 * @lc app=leetcode id=1935 lang=javascript
 *
 * [1935] Maximum Number of Words You Can Type
 */

// @lc code=start
/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function (text, brokenLetters) {
    let brokenalpha = new Array(26)
    for (let a of brokenLetters) {
        brokenalpha[a.charCodeAt() - 'a'.charCodeAt()] = 1
    }
    let res = 0;
    let error = 0;
    for (let a of text) {
        if (a === ' ') {
            if (error === 0) {
                ++res;
            }
            error = 0;
        } else if (error > 0) {
            continue;
        } else if (brokenalpha[a.charCodeAt() - 'a'.charCodeAt()]) {
            ++error;
        }
    }
    return res + (error === 0 ? 1 : 0);
};
// @lc code=end