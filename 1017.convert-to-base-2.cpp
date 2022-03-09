/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */
#include <string>
using namespace std;
// @lc code=start
// t:O(log(n)), s:O(log(n))
class Solution
{
public:
    string baseNeg2(int n)
    {
        int val = 1;
        string res = "1";
        while (val < n)
        {
            val <<= 2;
            val += 1;
            res.append("01");
        }
        int n_shift = 29;
        int w = res.size();
        while (n_shift >= 0)
        {
            if (val - (1 << n_shift) >= n)
            {
                if (n_shift % 2)
                {
                    res[w - n_shift - 1] = '1';
                }
                else
                {
                    res[w - n_shift - 1] = '0';
                }
                val -= (1 << n_shift);
            }
            n_shift -= 1;
        }
        return res;
    }
};
// @lc code=end

// t:O(log(n)), s:O(log(n))
// class Solution
// {
// public:
//     string baseNeg2(int n)
//     {
//         if (n == 0)
//         {
//             return "0";
//         }
//         bool pass = false;
//         bool odd = true;
//         string res;
//         while (n || pass)
//         {
//             if (n & 1)
//             {
//                 if (pass)
//                 {
//                     res.push_back('0');
//                 }
//                 else
//                 {
//                     res.push_back('1');
//                     if (!odd)
//                     {
//                         pass = true;
//                     }
//                 }
//             }
//             else
//             {
//                 if (pass)
//                 {
//                     res.push_back('1');
//                     if (!odd)
//                     {
//                         pass = true;
//                     }
//                     else
//                     {
//                         pass = false;
//                     }
//                 }
//                 else if (n)
//                 {
//                     res.push_back('0');
//                 }
//             }
//             odd = !odd;
//             n >>= 1;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };