
/*
 * @lc app=leetcode id=438 lang=java
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
import java.text.CharacterIterator;
import java.text.StringCharacterIterator;
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<Integer>(s.length());
        int p_len = p.length();
        int s_len = s.length();
        if(s_len<p_len){
            return res;
        }
        int[] p_count = new int[26];
        var iter_p = new StringCharacterIterator(p);
        while (iter_p.current() != CharacterIterator.DONE) {
            p_count[iter_p.current() - 'a']++;
            iter_p.next();
        }
        var iter_s = new StringCharacterIterator(s);
        while (iter_s.getIndex() != p_len) {
            p_count[iter_s.current() - 'a']--;
            iter_s.next();
        }
        int diff_count = 0;
        for (var n : p_count) {
            if (n != 0) {
                ++diff_count;
            }
        }
        if (diff_count == 0) {
            res.add(0);
        }
        while (iter_s.current() != CharacterIterator.DONE) {
            if (--p_count[iter_s.current() - 'a'] == 0) {
                --diff_count;
            } else if (p_count[iter_s.current() - 'a'] == -1) {
                ++diff_count;
            }
            if (++p_count[s.charAt(iter_s.getIndex() - p_len ) - 'a'] == 0) {
                --diff_count;
            } else if (p_count[s.charAt(iter_s.getIndex() - p_len ) - 'a'] == 1) {
                ++diff_count;
            }
            if (diff_count == 0) {
                res.add(iter_s.getIndex() - p_len + 1);
            }
            iter_s.next();
        }
        return res;
    }
}
// @lc code=end
