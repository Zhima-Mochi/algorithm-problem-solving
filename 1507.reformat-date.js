/*
 * @lc app=leetcode id=1507 lang=javascript
 *
 * [1507] Reformat Date
 */

// @lc code=start
/**
 * @param {string} date
 * @return {string}
 */
const month_to_num = {
    "Jan": "01",
    "Feb": "02",
    "Mar": "03",
    "Apr": "04",
    "May": "05",
    "Jun": "06",
    "Jul": "07",
    "Aug": "08",
    "Sep": "09",
    "Oct": "10",
    "Nov": "11",
    "Dec": "12"
};
var reformatDate = function (date) {
    let data = date.split(' ');
    data[0] = data[0].slice(0, data[0].length - 2);
    if (data[0].length == 1) {
        data[0] = '0' + data[0];
    }
    data[1] = month_to_num[data[1]];
    return data.reverse().join('-');
};
// @lc code=end