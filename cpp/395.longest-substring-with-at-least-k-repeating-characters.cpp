/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */
#include <string>
#include <unordered_map>
#include <array>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        array<short, 26> word_count, sub_word_count;
        word_count.fill(0);
        sub_word_count.fill(0);
        for (auto c : s)
        {
            ++word_count[c - 'a'];
        }
        int left = 0, right = 0;
        int width = s.size();
        int res = 0;
        while (right < width && width - left > res)
        {
            if (word_count[s[right] - 'a']-- < k && sub_word_count[s[right] - 'a'] + 1 + word_count[s[right] - 'a'] < k)
            {
                sub_word_count.fill(0);
                left = ++right;
            }
            else
            {
                ++sub_word_count[s[right] - 'a'];
                ++right;
                if (sub_word_count[s[right - 1] - 'a'] >= k)
                {
                    checkLength(res, left, right, s, k, sub_word_count);
                }
            }
        }
        return res;
    }
    void checkLength(int &res, int left, int right, const string &s, const int &k, array<short, 26> sub_word_count)
    {
        if (right - left < k || right - left <= res)
        {
            return;
        }
        bool pass = true;
        for (auto &n : sub_word_count)
        {
            if (n > 0 && n < k)
            {
                pass = false;
                break;
            }
        }
        if (pass)
        {
            res = max(res, right - left);
        }
        else
        {
            while (right - left >= k && right - left > res)
            {
                if (--sub_word_count[s[left++] - 'a'] == 0)
                {
                    bool pass = true;
                    for (auto &n : sub_word_count)
                    {
                        if (n > 0 && n < k)
                        {
                            pass = false;
                            break;
                        }
                    }
                    if (pass)
                    {
                        res = max(res, right - left);
                        break;
                    }
                }
            }
        }
    }
};
// @lc code=end
