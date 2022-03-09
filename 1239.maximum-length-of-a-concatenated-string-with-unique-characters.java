import java.util.ArrayList;

/*
 * @lc app=leetcode id=1239 lang=java
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> ls = new ArrayList<>();
        for (String s : arr) {
            Integer val = 0;
            for (Character c : s.toCharArray()) {
                if ((val & 1 << c - 'a') == 0) {
                    val |= 1 << c - 'a';
                } else {
                    val = 0;
                    break;
                }
            }
            if (!val.equals(0)) {
                ls.add(val);
            }
        }
        int[] res = new int[] { 0 };
        dfs(res, ls, 0, 0);
        return res[0];
    }

    void dfs(int[] res, List<Integer> ls, int current, int pos) {
        res[0] = Math.max(res[0], Integer.bitCount(current));
        if (pos == ls.size()) {
            return;
        }
        for (int i = pos; i != ls.size(); ++i) {
            if ((current & ls.get(i)) == 0) {
                dfs(res, ls, current | ls.get(i), i + 1);
            }
        }
    }
}
// @lc code=end
