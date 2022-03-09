import java.util.Arrays;

/*
 * @lc app=leetcode id=556 lang=java
 *
 * [556] Next Greater Element III
 */

// @lc code=start
class Solution {
    public int nextGreaterElement(int n) {
        // Character[] n_str = Integer.toString(n).chars().mapToObj(c -> (char)
        // c).toArray(Character[]::new);
        char[] n_str = Integer.toString(n).toCharArray();
        int width = n_str.length;
        int swap_pos_left = width - 2;
        while (swap_pos_left > -1) {
            if (n_str[swap_pos_left] < n_str[swap_pos_left + 1]) {
                break;
            }
            --swap_pos_left;
        }
        if (swap_pos_left == -1) {
            return -1;
        } else {
            int swap_pos_right = width - 1;
            while (n_str[swap_pos_right] <= n_str[swap_pos_left]) {
                --swap_pos_right;
            }
            char temp = n_str[swap_pos_left];
            n_str[swap_pos_left] = n_str[swap_pos_right];
            n_str[swap_pos_right] = temp;
            Arrays.sort(n_str, swap_pos_left + 1, width);
            long res = Long.parseLong(new String(n_str));
            return res > Integer.MAX_VALUE ? -1 : (int) res;
        }
    }
}
// @lc code=end
