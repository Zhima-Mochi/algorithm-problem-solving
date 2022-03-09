/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int len = words.size();
        int res = 0;
        vector<int> alphaCheck_vec;
        for (auto i = 0; i != len; ++i)
        {
            int alphaCheck = 0;
            for (auto c : words[i])
            {
                alphaCheck |= 1 << c - 'a';
            }
            alphaCheck_vec.push_back(alphaCheck);
        }
        for (auto i = 0; i != len - 1; ++i)
        {
            for (auto j = i + 1; j != len; ++j)
            {
                if ((alphaCheck_vec[i] & alphaCheck_vec[j]) == 0)
                {
                    res = max(res, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int maxProduct(vector<string> &words)
//     {
//         sort(words.begin(), words.end(), [](string &a, string &b)
//              { return a.size() > b.size(); });
//         int len = words.size();
//         int res = 0;
//         vector<bitset<26>> alphaCheck_vec;
//         for (auto i = 0; i != len; ++i)
//         {
//             bitset<26> alphaCheck;
//             for (auto c : words[i])
//             {
//                 alphaCheck.set(c - 'a');
//             }
//             alphaCheck_vec.push_back(alphaCheck);
//         }
//         for (auto i = 0; i != len - 1; ++i)
//         {
//             for (auto j = i + 1; j != len; ++j)
//             {
//                 if (res > words[i].size() * words[j].size())
//                 {
//                     break;
//                 }
//                 if ((alphaCheck_vec[i].to_ulong() & alphaCheck_vec[j].to_ulong()) == 0)
//                 {
//                     res = max(res, static_cast<int>(words[i].size() * words[j].size()));
//                 }
//             }
//         }
//         return res;
//     }
// };