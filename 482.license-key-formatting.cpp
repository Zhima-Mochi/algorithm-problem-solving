/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        int loop_count = 0;
        reverse(s.begin(), s.end());
        string res;
        for (auto c : s)
        {
            if (c != '-')
            {
                res.push_back(toupper(c));
                ++loop_count;
                if (loop_count % k == 0)
                {
                    res.push_back('-');
                }
            }
        }
        if (res.back() == '-')
        {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;


        // int count = 0;
        // for (auto c : s)
        // {
        //     if (c == '-')
        //     {
        //         ++count;
        //     }
        // }
        // int loop_count = k - ((s.size() - count) % k);

        // string res;
        // for (auto c : s)
        // {
        //     if (c != '-')
        //     {
        //         res.push_back(toupper(c));
        //         ++loop_count;
        //         if (loop_count % k == 0)
        //         {
        //             res.push_back('-');
        //         }
        //     }
        // }
        // if (res.back() == '-')
        // {
        //     res.pop_back();
        // }
        // return res;
    }
};
// @lc code=end
