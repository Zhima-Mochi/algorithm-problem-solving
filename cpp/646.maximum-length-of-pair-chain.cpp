/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// T:O(N LOG N) S:O(1)
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), [](vector<int> &l, vector<int> &r)
             { return l[1] < r[1]; });
        int cur_pos = INT_MIN;
        int res = 0;
        for (auto &pair : pairs)
        {
            if (pair[0] > cur_pos)
            {
                ++res;
                cur_pos = pair[1];
            }
        }
        return res;
    }
};
// @lc code=end

// T:O(2002) S:O(2002)
// class Solution
// {
// public:
//     int findLongestChain(vector<vector<int>> &pairs)
//     {
//         vector<int> bucket_sort(2002, INT_MAX);
//         vector<int> dp(2002, 0);
//         for (auto &pair : pairs)
//         {
//             bucket_sort[pair[0] + 1000] = min(bucket_sort[pair[0] + 1000], pair[1] + 1000);
//         }
//         if (bucket_sort[0] != INT_MAX)
//         {
//             dp[bucket_sort[0] + 1] = 1;
//         }
//         for (int i = 1; i != 2002; ++i)
//         {
//             dp[i] = max(dp[i], dp[i - 1]);
//             if (bucket_sort[i] != INT_MAX)
//             {
//                 dp[bucket_sort[i] + 1] = max(dp[bucket_sort[i] + 1], dp[i] + 1);
//             }
//         }
//         return dp.back();
//     }
// };