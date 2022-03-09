/*
 * @lc app=leetcode id=1304 lang=java
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
class Solution {
    public int[] sumZero(int n) {
        int[] res = new int[n];
        if (n % 2 == 1) {
            res[n - 1] = 0;
            --n;
        }
        n /= 2;
        int ind = 0;
        while (n > 0) {
            res[ind++] = n;
            res[ind++] = -n;
            --n;
        }
        return res;
    }
}
// @lc code=end
