/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0, len = s.size();
        vector<int> count(26, 0);
        int max_alpha_count = 0;
        int res = k;
        for (; right != len; ++right)
        {
            if (max_alpha_count < ++count[s[right] - 'A'])
            {
                max_alpha_count = count[s[right] - 'A'];
                res = max(res, max_alpha_count + k);
            }
            else
            {
                while (right - left + 1 - max_alpha_count > k)
                {
                    --count[s[left++] - 'A'];
                    //max_alpha_count = *max_element(count.begin(), count.end());
                }
            }
        }
        return res > len ? len : res;
    }
};
// @lc code=end