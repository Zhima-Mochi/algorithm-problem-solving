import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

/*
 * @lc app=leetcode id=522 lang=java
 *
 * [522] Longest Uncommon Subsequence II
 */

// @lc code=start
class Solution {
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, new Comparator<String>() {
            @Override
            public int compare(String l, String r) {
                if (l.length() != r.length()) {
                    return r.length() - l.length();
                } else {
                    return r.compareTo(l);
                }
            }
        });
        List<String> repeat_strs = new ArrayList<>();
        int len = strs.length;
        for (int i = 0; i < len; ++i) {
            if (i + 1 == len || strs[i].compareTo(strs[i + 1]) != 0) {
                boolean pass = true;
                for (String str : repeat_strs) {
                    if (strs[i].length() >= str.length()) {
                        break;
                    }
                    if (isSubstr(strs[i], str)) {
                        pass = false;
                        break;
                    }
                }
                if (pass) {
                    return strs[i].length();
                }
            } else {
                repeat_strs.add(strs[i]);
                // we can also use binary search
                while (i + 1 != len && strs[i + 1].compareTo(strs[i]) == 0) {
                    ++i;
                }
            }
        }
        return -1;
    }

    boolean isSubstr(String l, String r) {
        int left = 0, right = 0;
        int l_len = l.length(), r_len = r.length();
        while (left != l_len && right != r_len) {
            if (l.charAt(left) == r.charAt(right)) {
                ++left;
                ++right;
            } else {
                ++right;
            }
        }
        return left == l_len;
    }
}
// @lc code=end
