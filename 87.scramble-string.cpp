/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n^4), s:O(n^3)
class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int w = s1.size();
        unordered_map<int, bool> records;
        function<bool(int, int, int, int)> dp = [&](int left1, int right1, int left2, int right2)
        {
            if (right1 - left1 == 1)
            {
                return s1[left1] == s2[left2];
            }
            int key = left1 * 1024 + left2 * 32 + right1 - left1;
            if (records.count(key))
            {
                return records[key];
            }
            string s1_count(26, 0), s2_count(26, 0);
            for (int i = left1; i != right1; ++i)
            {
                ++s1_count[s1[i] - 'a'];
            }
            for (int i = left2; i != right2; ++i)
            {
                ++s2_count[s2[i] - 'a'];
            }
            if (s1_count != s2_count)
            {
                return records[key] = false;
            }
            s1_count = string(26, 0);
            s2_count = string(26, 0);
            for (int i = 0; i != right1 - left1 - 1; ++i)
            {
                ++s1_count[s1[left1 + i] - 'a'];
                ++s2_count[s2[left2 + i] - 'a'];
                if (s1_count == s2_count)
                {
                    if (dp(left1, left1 + i + 1, left2, left2 + i + 1) && dp(left1 + i + 1, right1, left2 + i + 1, right2))
                    {
                        return records[key] = true;
                    }
                }
            }
            s1_count = string(26, 0);
            s2_count = string(26, 0);
            for (int i = 0; i != right1 - left1 - 1; ++i)
            {
                ++s1_count[s1[left1 + i] - 'a'];
                ++s2_count[s2[right2 - 1 - i] - 'a'];
                if (s1_count == s2_count)
                {
                    if (dp(left1, left1 + i + 1, right2 - 1 - i, right2) && dp(left1 + i + 1, right1, left2, right2 - 1 - i))
                    {
                        return records[key] = true;
                    }
                }
            }
            return records[key] = false;
        };
        return dp(0, w, 0, w);
    }
};
// @lc code=end
