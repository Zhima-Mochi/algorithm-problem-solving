/*
 * @lc app=leetcode id=393 lang=java
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
class Solution {
    public boolean validUtf8(int[] data) {
        byte neededOneZeroCount = 0;
        for (var val : data) {
            if (neededOneZeroCount == 0) {
                if ((val & (1 << 7)) == 0) {
                    continue;
                } else if ((val >> 5) == 0x06) {
                    neededOneZeroCount = 1;
                } else if ((val >> 4) == 0x0e) {
                    neededOneZeroCount = 2;
                } else if ((val >> 3) == 0x1e) {
                    neededOneZeroCount = 3;
                } else {
                    return false;
                }
            } else {
                if ((val >> 6) != 0x02) {
                    return false;
                } else {
                    --neededOneZeroCount;
                }
            }
        }
        return neededOneZeroCount == 0;
    }
}
// @lc code=end
