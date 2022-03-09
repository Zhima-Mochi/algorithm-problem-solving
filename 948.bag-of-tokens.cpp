/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(nlog(n)), s:O(1)
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        int w = tokens.size();
        if (w == 0)
        {
            return 0;
        }
        sort(tokens.begin(), tokens.end());
        int left = 0, right = w - 1;
        int scores = 0;
        int res = 0;
        while (left <= right && (power >= tokens[left] || scores > 0))
        {
            while (left <= right && power >= tokens[left])
            {
                power -= tokens[left++];
                ++scores;
            }
            res = max(res, scores);
            if (left <= right && scores > 0)
            {
                power += tokens[right--];
                --scores;
            }
        }
        return res;
    }
};
// @lc code=end
// t:O(nlog(n)), s:O(1)
// class Solution
// {
// public:
//     int bagOfTokensScore(vector<int> &tokens, int power)
//     {
//         int w = tokens.size();
//         if (w == 0)
//         {
//             return 0;
//         }
//         sort(tokens.begin(), tokens.end());
//         int idx = 0;
//         for (; idx < w / 2 - 1; ++idx)
//         {
//             if (power < tokens[idx])
//             {
//                 break;
//             }
//             power += tokens[w - 1 - idx] - tokens[idx];
//         }
//         int scores = 0;
//         while (idx + scores < w && power >= tokens[idx + scores])
//         {
//             power -= tokens[idx + scores];
//             ++scores;
//         }
//         while (--idx >= 0)
//         {
//             power -= tokens[w - 1 - idx] - tokens[idx];
//             if (power < tokens[idx])
//             {
//                 power += tokens[idx + scores];
//                 power -= tokens[idx];
//             }
//             else
//             {
//                 power -= tokens[idx];
//                 ++scores;
//             }
//         }
//         return scores;
//     }
// };