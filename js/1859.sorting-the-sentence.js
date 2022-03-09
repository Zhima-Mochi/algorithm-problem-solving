/*
 * @lc app=leetcode id=1859 lang=javascript
 *
 * [1859] Sorting the Sentence
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
var sortSentence = function (s) {
    const s_split = s.split(' ');
    const res_arr = Array(s_split.length);
    s_split.forEach(item => {
        res_arr[+item[item.length - 1] - 1] = item.slice(0, item.length - 1);
    });
    return res_arr.join(' ');
};
// @lc code=end