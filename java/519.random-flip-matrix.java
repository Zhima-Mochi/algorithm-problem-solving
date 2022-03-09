import java.util.HashMap;
import java.util.Map;
import java.util.Random;

/*
 * @lc app=leetcode id=519 lang=java
 *
 * [519] Random Flip Matrix
 */

// @lc code=start
class Solution {
    Map<Integer, Integer> seen = new HashMap<>();
    int height;
    int width;
    int total;
    Random rand = new Random();

    public Solution(int m, int n) {
        height = m;
        width = n;
        total = m * n;
    }

    public int[] flip() {
        int choose = rand.nextInt(total--);
        int res = seen.getOrDefault(choose, choose);
        seen.put(choose, seen.getOrDefault(total, total));
        return new int[] { res / width, res % width };
    }

    public void reset() {
        seen.clear();
        total = height * width;
    }
}

/**
 * Your Solution object will be instantiated and called as such: Solution obj =
 * new Solution(m, n); int[] param_1 = obj.flip(); obj.reset();
 */
// @lc code=end
