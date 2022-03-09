
import java.util.ArrayList;

/*
 * @lc app=leetcode id=1108 lang=java
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
import java.text.CharacterIterator;
import java.text.StringCharacterIterator;
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder res = new StringBuilder();
        var iter = new StringCharacterIterator(address);
        while (iter.current() != CharacterIterator.DONE) {
            if (iter.current() != '.') {
                res.append(iter.current());
            } else {
                res.append("[.]");
            }
            iter.next();
        }
        return res.toString();
    }
}
// @lc code=end
