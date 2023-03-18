/*
 * @lc app=leetcode id=2315 lang=typescript
 *
 * [2315] Count Asterisks
 */

// @lc code=start
function countAsterisks(s: string): number {
    let res: number = 0;
    let l: number = 0;
    for (let c of s) {
        if (c === '*') {
            if (l === 0) {
                res += 1;
            }
        } else if (c === '|') {
            l += 1;
            l %= 2;
        }
    }
    return res;
};
// @lc code=end

