import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

/*
 * @lc app=leetcode id=899 lang=java
 *
 * [899] Orderly Queue
 */

// @lc code=start
class Solution {
    public String orderlyQueue(String s, int k) {
        if (k > 1) {
            var s_arr = s.toCharArray();
            Arrays.sort(s_arr);
            return new String(s_arr);
        } else {
            // why ArrayDeque do not implement random access?
            String candidate = new String(s);
            int len = s.length();
            for (int i = 0; i < len - 1; ++i) {
                s = s.substring(1) + s.substring(0, 1);
                if (s.compareTo(candidate) < 0) {
                    candidate = s;
                }
            }
            return candidate;
        }
    }

}
// @lc code=end
