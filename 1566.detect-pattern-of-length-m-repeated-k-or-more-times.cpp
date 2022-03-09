/*
 * @lc app=leetcode id=1566 lang=cpp
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        int dp = m;
        for (int i = m, width = arr.size(); i != width; ++i)
        {
            if (arr[i] == arr[i - m])
            {
                dp += 1;
                if (dp == k * m)
                {
                    return true;
                }
            }
            else
            {
                dp = m;
            }
        }
        return false;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     bool containsPattern(vector<int> &arr, int m, int k)
//     {
//         vector<int> dp(m, 1);
//         for (int i = m, width = arr.size(); i != width; ++i)
//         {
//             if (arr[i] == arr[i - m])
//             {
//                 dp[i % m] += 1;
//                 if (dp[i % m] == k)
//                 {
//                     bool pass = true;
//                     for (auto n : dp)
//                     {
//                         if (n < k)
//                         {
//                             pass = false;
//                             break;
//                         }
//                     }
//                     if (pass)
//                     {
//                         return true;
//                     }
//                 }
//             }
//             else
//             {
//                 dp[i % m] = 1;
//             }
//         }
//         return false;
//     }
// };