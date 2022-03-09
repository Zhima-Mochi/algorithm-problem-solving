/*
 * @lc app=leetcode id=1399 lang=java
 *
 * [1399] Count Largest Group
 */

// @lc code=start
class Solution {
    public int countLargestGroup(int n) {
        int[] vec = new int[37];
        for (int i = 1; i != n + 1; ++i) {
            ++vec[helpler(i)];
        }
        int max_size = 0;
        int res = 0;
        for (var v : vec) {
            if (v > max_size) {
                res = 1;
                max_size = v;
            } else if (v == max_size) {
                ++res;
            }
        }
        return res;
    }

    int helpler(int num) {
        int res = 0;
        while (num > 0) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
}
// @lc code=end
