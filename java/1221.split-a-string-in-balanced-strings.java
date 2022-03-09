
/*
* @lc app=leetcode id=1221 lang=java
*
* [1221] Split a String in Balanced Strings
*/

// @lc code=start
import java.text.StringCharacterIterator;
class Solution {
    public int balancedStringSplit(String s) {
        int R_count = 0;
        int res = 0;
        StringCharacterIterator c = new StringCharacterIterator(s);
        while (c.current() != StringCharacterIterator.DONE) {
            if (c.current() == 'R') {
                ++R_count;
            } else {
                --R_count;
            }
            if (R_count == 0 ) {
                ++res;
            }
            c.next();
        }
        return res;
    }
}
// @lc code=end
