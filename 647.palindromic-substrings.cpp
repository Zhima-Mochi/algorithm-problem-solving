/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    int width;

public:
    int countSubstrings(string s)
    {
        width = s.size();
        int res = 0;
        for (int i = 0; i != width; ++i)
        {
            helpler(res, s, i, i);
            helpler(res, s, i, i + 1);
        }
        return res;
    }
    void helpler(int &res, string &s, int left, int right)
    {
        while (left >= 0 && right < width)
        {
            if (s[left--] == s[right++])
            {
                ++res;
            }
            else
            {
                break;
            }
        }
    }
};
// @lc code=end
// class Solution
// {
// public:
//     int countSubstrings(string s)
//     {
//         int width = s.size();
//         bool *prev_palin_length = new bool[width + 3]();
//         prev_palin_length[0] = true;
//         prev_palin_length[1] = true;
//         int res = 1;
//         for (int i = 1; i != width; ++i)
//         {
//             ++res;
//             for (int j = width; j != -1; --j)
//             {
//                 if (prev_palin_length[j])
//                 {
//                     if (i - j - 1 >= 0 && s[i - j - 1] == s[i])
//                     {
//                         ++res;
//                         prev_palin_length[j + 2] = true;
//                     }
//                     else
//                     {
//                         prev_palin_length[j + 2] = false;
//                     }
//                 }
//                 else
//                 {
//                     prev_palin_length[j + 2] = false;
//                 }
//             }
//         }
//         return res;
//     }
// };