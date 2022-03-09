import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/*
 * @lc app=leetcode id=115 lang=java
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
    public int numDistinct(String s, String t) {
        if (s.equals(t)) {
            return 1;
        }
        if (!check_has_substring(s, t)) {
            return 0;
        }
        Map<Character, ArrayList<String>> pre_word_map = new HashMap<>();
        Map<String, Long> match_word_count = new HashMap<>();
        int t_len = t.length();
        for (int i = 1; i < t_len; ++i) {
            var pre_word = t.substring(0, i);
            if (!pre_word_map.containsKey(t.charAt(i))) {
                pre_word_map.put(t.charAt(i), new ArrayList<>());
            }
            pre_word_map.get(t.charAt(i)).add(pre_word);
        }
        var first_word_string = t.substring(0, 1);
        int s_len = s.length();
        for (int i = 0; i < s_len; ++i) {
            int candidate_size = pre_word_map.getOrDefault(s.charAt(i), new ArrayList<>()).size();
            for (int j = candidate_size - 1; j >= 0; --j) {
                var pre_word = pre_word_map.get(s.charAt(i)).get(j);
                var extended_pre_word = pre_word + s.charAt(i);
                match_word_count.put(extended_pre_word, match_word_count.getOrDefault(extended_pre_word, 0L)
                        + match_word_count.getOrDefault(pre_word, 0L));
            }
            if (s.charAt(i) == t.charAt(0)) {
                match_word_count.put(first_word_string, match_word_count.getOrDefault(first_word_string, 0L) + 1);
            }
        }
        return match_word_count.get(t).intValue();
    }

    boolean check_has_substring(String s, String t) {
        if (t.length() > s.length()) {
            return false;
        }
        int pos = 0;
        int t_len = t.length();
        for (int i = 0; i != t_len; ++i) {
            var next_pos = s.indexOf(t.charAt(i), pos);
            if (next_pos == -1) {
                return false;
            } else {
                pos = next_pos + 1;
            }
        }
        return true;
    }
}
// @lc code=end
