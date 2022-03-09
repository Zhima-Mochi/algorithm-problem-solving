/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
// n=len(strs), m=len(strs[0])
// t:O(nm), s:O(n)
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int w = strs.size();
        int w_word = strs[0].size();
        vector<bool> break_pt(w);
        int res = 0;

        for (int i = 0; i != w_word; ++i)
        {
            bool flag = true;
            for (int j = 0; j < w - 1; ++j)
            {
                if (!break_pt[j] && strs[j][i] > strs[j + 1][i])
                {
                    ++res;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int j = 0; j < w - 1; ++j)
                {
                    if (strs[j][i] < strs[j + 1][i])
                    {
                        break_pt[j] = true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
// n=len(strs), m=len(strs[0])
// t:O(nmm), s:O(1)
// class Solution
// {
// public:
//     int minDeletionSize(vector<string> &strs)
//     {
//         int w = strs.size();
//         int w_word = strs[0].size();
//         int idx = 0;
//         int res = 0;
//         while (idx < w_word)
//         {
//             bool flag = true;
//             string prev = strs[0].substr(0, idx + 1);
//             for (int i = 1; i != w; ++i)
//             {
//                 string next = strs[i].substr(0, idx + 1);
//                 if (next < prev)
//                 {
//                     flag = false;
//                     break;
//                 }
//                 prev = next;
//             }
//             if (!flag)
//             {
//                 ++res;
//                 for (int i = 0; i != w; ++i)
//                 {
//                     strs[i][idx] = 0;
//                 }
//             }
//             ++idx;
//         }
//         return res;
//     }
// };