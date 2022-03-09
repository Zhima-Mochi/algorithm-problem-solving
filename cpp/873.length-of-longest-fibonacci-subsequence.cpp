/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start

// t:O(len(arr)^2), s:O(len(arr)*log(max(arr)))
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int w = arr.size();
        int res = 0;
        unordered_map<int, int> arr_idx;
        int idx = 0;
        for (auto n : arr)
        {
            arr_idx[n] = idx++;
        }
        unordered_map<int, int> dp;
        for (int i = 0; i < w - 1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int prev_1 = i;
                int prev_2 = j;
                int l = 2;
                while (arr_idx.count(arr[prev_1] + arr[prev_2]) && dp[(prev_1 << 10) + prev_2] < l + 1)
                {
                    ++l;
                    int sum = arr[prev_1] + arr[prev_2];
                    dp[(prev_1 << 10) + prev_2] = l;
                    res = max(l, res);
                    prev_2 = prev_1;
                    prev_1 = arr_idx[sum];
                }
            }
        }
        return res;
    }
};
// @lc code=end
// t:O(len(arr)^2*log(max(arr))), s:O(len(arr))
// class Solution
// {
// public:
//     int lenLongestFibSubseq(vector<int> &arr)
//     {
//         int w = arr.size();
//         int res = 0;
//         unordered_map<int, int> dp;
//         for (auto n : arr)
//         {
//             dp[n] = 1;
//         }
//         for (int i = 0; i < w - 1; ++i)
//         {
//             for (int j = 0; j < i; ++j)
//             {
//                 int prev_1 = arr[i];
//                 int prev_2 = arr[j];
//                 int l = 2;
//                 while (dp.count(prev_1 + prev_2))
//                 {
//                     ++l;
//                     int sum = prev_1 + prev_2;
//                     dp[sum] = max(dp[sum], l);
//                     res = max(dp[sum], res);
//                     prev_2 = prev_1;
//                     prev_1 = sum;
//                 }
//             }
//         }
//         return res;
//     }
// };