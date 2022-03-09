import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=1078 lang=java
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] split_text = text.split(" ");
        List<String> res = new ArrayList<>();
        for (int i = 2, len = split_text.length; i < len; ++i) {
            if (split_text[i - 2].equals(first) && split_text[i - 1].equals(second)) {
                res.add(split_text[i]);
            }
        }
        return res.toArray(new String[0]);
    }
}
// @lc code=end
