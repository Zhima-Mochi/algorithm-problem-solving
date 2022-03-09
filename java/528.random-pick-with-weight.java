import java.util.Arrays;
import java.util.Random;

/*
 * @lc app=leetcode id=528 lang=java
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
    int[] accum;
    int sum_val;
    Random rand = new Random();

    public Solution(int[] w) {
        accum = new int[w.length];
        sum_val = 0;
        for (int i = 0; i < w.length; ++i) {
            sum_val += w[i];
            accum[i] = sum_val;
        }
    }

    public int pickIndex() {
        int pick_val = rand.nextInt(sum_val) + 1;
        int pick = Arrays.binarySearch(accum, pick_val);
        return pick >= 0 ? pick : -(pick + 1);
    }
}

/**
 * Your Solution object will be instantiated and called as such: Solution obj =
 * new Solution(w); int param_1 = obj.pickIndex();
 */
// @lc code=end
