import java.util.Arrays;

/*
 * @lc app=leetcode id=1417 lang=java
 *
 * [1417] Reformat The String
 */

// @lc code=start
class Solution {
    public String reformat(String s) {
        int width = s.length();
        if (width == 1) {
            return s;
        }
        var s_arr = s.toCharArray();
        int num_count = (int) s.chars().filter(i -> Character.isDigit(i)).count();
        if (num_count != width / 2 && num_count != (width + 1) / 2) {
            return "";
        }
        boolean num_first = num_count > width / 2;
        int left = 0;
        int right = width % 2 == 1 ? width - 2 : width - 1;
        while (left < width && right > -1) {
            if (num_first) {
                if (Character.isDigit(s_arr[left])) {
                    left += 2;
                    continue;
                }
                if (Character.isAlphabetic(s_arr[right])) {
                    right -= 2;
                    continue;
                }
            } else {
                if (!Character.isDigit(s_arr[left])) {
                    left += 2;
                    continue;
                }
                if (!Character.isAlphabetic(s_arr[right])) {
                    right -= 2;
                    continue;
                }
            }
            var temp = s_arr[left];
            s_arr[left] = s_arr[right];
            s_arr[right] = temp;
            left += 2;
            right -= 2;
        }
        return new String(s_arr);
    }
}
// @lc code=end
