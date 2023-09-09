/*
 * @lc app=leetcode id=2182 lang=cpp
 *
 * [2182] Construct String With Repeat Limit
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> cnt(26, 0);
        for (auto c : s)
        {
            cnt[c - 'a'] += 1;
        }
        int right = 25;
        while (right >= 0 && cnt[right] == 0)
        {
            right -= 1;
        }
        string res = "";
        while (right >= 0)
        {
            if (cnt[right] == 0)
            {
                right -= 1;
            }
            else
            {
                if (cnt[right] > repeatLimit)
                {
                    res += string(repeatLimit, 'a' + right);
                    cnt[right] -= repeatLimit;
                    int left = right - 1;
                    while (left >= 0 && cnt[left] == 0)
                    {
                        left -= 1;
                    }
                    if (left == -1)
                    {
                        break;
                    }
                    else
                    {
                        res += string(1, 'a' + left);
                        cnt[left] -= 1;
                    }
                }
                else
                {
                    res += string(cnt[right], 'a' + right);
                    cnt[right] = 0;
                }
            }
        }
        return res;
    }
};
// @lc code=end
