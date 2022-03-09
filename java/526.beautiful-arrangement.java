/*
 * @lc app=leetcode id=526 lang=java
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution {
    int res = 0;

    public int countArrangement(int n) {
        boolean[] seen = new boolean[n];
        backtrack(n, seen);
        return res;
    }

    void backtrack(int n, boolean[] seen) {
        if (n == 0) {
            ++res;
            return;
        }
        for (int i = 0; i < seen.length; ++i) {
            if (!seen[i] && ((n % (i + 1)) == 0 || ((i + 1) % n) == 0)) {
                seen[i] = true;
                backtrack(n - 1, seen);
                seen[i] = false;
            }
        }
    }
}
// @lc code=end
