import java.lang.System.Logger;

import jdk.internal.net.http.common.Log;

/*
 * @lc app=leetcode id=1071 lang=java
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        if ((str1 + str2).equals(str2 + str1)) {
            return str1.substring(0, gcd(str1.length(), str2.length()));
        } else {
            return "";
        }
    }
    static int gcd(int a, int b) {
        while (b != 0) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        return a;
    }
}
// @lc code=end
