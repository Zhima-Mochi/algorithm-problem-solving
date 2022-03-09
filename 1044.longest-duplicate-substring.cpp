/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
#define mod 10000000000007
class Solution
{
public:
    string longestDupSubstring(string s)
    {
        int width = s.size();
        int left = 0, right = width - 1;
        string res = "";
        while (left < right)
        {
            int mid = left + (right - left) / 2 + 1;
            long long head_string_code = 0;
            for (int i = 0; i != mid; ++i)
            {
                head_string_code *= 26;
                head_string_code %= mod;
                head_string_code += s[i] - 'a';
            }
            unordered_set<long long> collections;
            collections.insert(head_string_code);
            long long mul_num = 1;
            for (int i = 0; i != mid - 1; ++i)
            {
                mul_num *= 26;
                mul_num %= mod;
            }
            for (int i = mid; i != width; ++i)
            {
                head_string_code -= static_cast<long long>(s[i - mid] - 'a') * mul_num % mod;
                head_string_code = (head_string_code + mod) % mod;
                head_string_code *= 26;
                head_string_code %= mod;
                head_string_code += s[i] - 'a';
                if (collections.count(head_string_code))
                {
                    left = mid;
                    res = s.substr(i - mid + 1, mid);
                    break;
                }
                else
                {
                    collections.insert(head_string_code);
                }
            }
            if (left != mid)
            {
                right = mid - 1;
            }
        }
        return res;
    }
};
// @lc code=end