/*
 * @lc app=leetcode id=825 lang=cpp
 *
 * [825] Friends Of Appropriate Ages
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        vector<int> record(121);
        for (auto age : ages)
        {
            ++record[age];
        }
        int res = 0;
        for (int i = 0; i != 121; ++i)
        {
            if (record[i] == 0)
            {
                continue;
            }
            else if (i < 2 * (i - 7))
            {
                res += record[i] * (record[i] - 1);
            }
            for (int j = i + 1, bd = min(121, 2 * (i - 7)); j < bd; ++j)
            {
                res += record[i] * record[j];
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int numFriendRequests(vector<int> &ages)
//     {
//         sort(ages.begin(), ages.end());
//         int width = ages.size();
//         int res = 0;
//         int prev = 0;
//         for (int i = 0; i != width; ++i)
//         {
//             if (i > 0 && ages[i] == ages[i - 1])
//             {
//                 res += prev;
//             }
//             else
//             {
//                 prev = lower_bound(ages.begin() + i + 1, ages.end(), 2 * (ages[i] - 7)) - (ages.begin() + i + 1);
//                 res += prev;
//             }
//         }
//         return res;
//     }
// };