/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */
#include <string>
#include <regex>
using namespace std;
// @lc code=start
class Solution
{
public:
    string validIPAddress(string IP)
    {
        static regex ipv4("(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])");
        static regex ipv6("([0-9a-fA-F]{1,4}\\:){7}[0-9a-fA-F]{1,4}");
        return regex_match(IP, ipv4) ? "IPv4" : regex_match(IP, ipv6) ? "IPv6"
                                                                      : "Neither";
    }
};
// @lc code=end
// class Solution
// {
// public:
//     string validIPAddress(string IP)
//     {
//         return checkIPv4(IP) ? "IPv4" : checkIPv6(IP) ? "IPv6"
//                                                       : "Neither";
//     }
//     bool checkIPv4(string &ip)
//     {
//         int dot_count = 0;
//         int val = -1;
//         for (auto c : ip)
//         {
//             if (c == '.')
//             {
//                 if (val == -1)
//                 {
//                     return false;
//                 }
//                 ++dot_count;
//                 if (dot_count > 3)
//                 {
//                     return false;
//                 }
//                 val = -1;
//             }
//             else if (isdigit(c))
//             {
//                 if (val == -1)
//                 {
//                     val = c - '0';
//                 }
//                 else
//                 {
//                     if (val == 0)
//                     {
//                         return false;
//                     }
//                     val *= 10;
//                     val += c - '0';
//                     if (val >= 256)
//                     {
//                         return false;
//                     }
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return dot_count == 3 && val != -1;
//     }
//     bool checkIPv6(string &ip)
//     {
//         int colon_count = 0;
//         int length = 0;
//         for (auto c : ip)
//         {
//             if (c == ':')
//             {
//                 if (!length)
//                 {
//                     return false;
//                 }
//                 ++colon_count;
//                 if (colon_count > 7)
//                 {
//                     return false;
//                 }
//                 length = 0;
//             }
//             else if (isdigit(c) || (c <= 'f' && c >= 'a') || (c <= 'F' && c >= 'A'))
//             {
//                 ++length;
//                 if (length > 4)
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return colon_count == 7 && length != 0;
//     }
// };