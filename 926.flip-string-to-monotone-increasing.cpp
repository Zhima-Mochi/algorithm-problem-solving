/*
 * @lc app=leetcode id=926 lang=cpp
 *
 * [926] Flip String to Monotone Increasing
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int count_one = 0, minFlip = 0;
        for (auto c : s)
        {
            if (c == '1')
            {
                ++count_one;
            }
            minFlip = min(count_one, c == '0' ? minFlip + 1 : minFlip);
        }
        return minFlip;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int minFlipsMonoIncr(string s)
//     {
//         int len = s.size();
//         int one_total = 0;
//         for (int i = 0; i != len; ++i)
//         {
//             if (s[i] == '1')
//             {
//                 ++one_total;
//             }
//         }
//         int res = min(one_total, len - one_total);
//         int one_accum = 0;
//         for (int i = 0; i != len; ++i)
//         {
//             if (s[i] == '1')
//             {
//                 res = min(one_accum + len - i - (one_total - one_accum), res);
//                 ++one_accum;
//             }
//         }
//         return res;
//     }
// };