/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start

// t:O(len(piles)*log(max(piles))), s:O(1)
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int w = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left < right)
        {
            int mid = left + (right - left >> 1);
            int total_consume = 0;
            for (auto p : piles)
            {
                total_consume += p % mid ? p / mid + 1 : p / mid;
                if (total_consume > h)
                {
                    break;
                }
            }
            if (total_consume <= h)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
// t:O(log(len(piles))*log(max(piles))), s:O(1)
// class Solution
// {
// public:
//     int minEatingSpeed(vector<int> &piles, int h)
//     {
//         int w = piles.size();
//         sort(piles.begin(), piles.end());
//         long long left = 1;
//         long long right = piles.back();
//         while (left < right)
//         {
//             long long mid = left + (right - left >> 1);
//             long long total_consume = 0;
//             int idx = 0;
//             long long consume_time = 1;
//             while (idx != w && total_consume <= h)
//             {
//                 int next_idx = upper_bound(piles.begin() + idx, piles.end(), mid * consume_time) - piles.begin();
//                 total_consume += (next_idx - idx) * consume_time;
//                 idx = next_idx;
//                 if (idx == w)
//                 {
//                     break;
//                 }
//                 consume_time = piles[next_idx] % mid ? piles[next_idx] / mid + 1 : piles[next_idx] / mid;
//             }
//             if (idx == w && total_consume <= h)
//             {
//                 right = mid;
//             }
//             else
//             {
//                 left = mid + 1;
//             }
//         }
//         return left;
//     }
// };