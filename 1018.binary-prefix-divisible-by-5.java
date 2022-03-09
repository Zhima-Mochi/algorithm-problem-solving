import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=1018 lang=java
 *
 * [1018] Binary Prefix Divisible By 5
 */

// @lc code=start
class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        byte val = 0;
        List<Boolean> res = new ArrayList<Boolean>();
        for (var n : nums) {
            val <<= 1;
            val += n;
            val %= 5;
            res.add(val == 0);
        }
        return res;
    }
}
// @lc code=end
