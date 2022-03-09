
/*
* @lc app=leetcode id=468 lang=java
*
* [468] Validate IP Address
*/

import java.net.Inet6Address;
import java.net.InetAddress;
// @lc code=start

class Solution {
    public String validIPAddress(String IP) {
        return checkIPv4(IP) ? "IPv4" : checkIPv6(IP) ? "IPv6" : "Neither";
    }

    boolean checkIPv4(String ip) {
        int dot_count = 0;
        int val = -1;
        //sorry to use toCharArray, use CharacterIterator is better
        for (var c : ip.toCharArray()) {
            if (c == '.') {
                if (val == -1) {
                    return false;
                }
                ++dot_count;
                if (dot_count > 3) {
                    return false;
                }
                val = -1;
            } else if (Character.isDigit(c)) {
                if (val == -1) {
                    val = c - '0';
                } else {
                    if (val == 0) {
                        return false;
                    }
                    val *= 10;
                    val += c - '0';
                    if (val >= 256) {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
        return dot_count == 3 && val != -1;
    }

    boolean checkIPv6(String ip) {
        int colon_count = 0;
        int length = 0;
        for (var c : ip.toCharArray()) {
            if (c == ':') {
                if (length == 0) {
                    return false;
                }
                ++colon_count;
                if (colon_count > 7) {
                    return false;
                }
                length = 0;
            } else if (Character.isDigit(c) || (c <= 'f' && c >= 'a') || (c <= 'F' && c >= 'A')) {
                ++length;
                if (length > 4) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return colon_count == 7 && length != 0;
    }
}
// @lc code=end

// import java.net.Inet6Address;
// import java.net.InetAddress;

// class Solution {
// public String validIPAddress(String IP) {
// try {
// return (InetAddress.getByName(IP) instanceof Inet6Address) ? "IPv6" : "IPv4";
// } catch (Exception e) {
// return "Neither";
// }
// }

// }
