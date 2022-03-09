import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=1431 lang=java
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> res = new ArrayList<>(candies.length);
        int max_val = Arrays.stream(candies).max().getAsInt();
        for (int n : candies) {
            if (n + extraCandies >= max_val) {
                res.add(true);
            } else {
                res.add(false);
            }
        }
        return res;
    }
}
// @lc code=end
