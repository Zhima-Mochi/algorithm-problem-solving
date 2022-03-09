/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int width = arr.size();
        int res = 0;
        for (int i = 0; i != width; ++i)
        {
            res += arr[i] * (((i + 1) * (width - i) + 1) / 2);
        }

        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int sumOddLengthSubarrays(vector<int> &arr)
//     {
//         int width = arr.size();
//         for (int i = 1; i != width; ++i)
//         {
//             arr[i] += arr[i - 1];
//         }
//         int res = arr.back();
//         for (int i = 2; i < width; i += 2)
//         {
//             res += arr[i];
//             for (int j = i + 1; j != width; ++j)
//             {
//                 res += arr[j] - arr[j - (i + 1)];
//             }
//         }
//         return res;
//     }
// };