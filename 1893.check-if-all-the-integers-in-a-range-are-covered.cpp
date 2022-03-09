/*
 * @lc app=leetcode id=1893 lang=cpp
 *
 * [1893] Check if All the Integers in a Range Are Covered
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {
        vector<int> record(52, 0);
        for (auto &&r : ranges)
        {
            ++record[r[0]];
            --record[r[1] + 1];
        }
        int count = 0;
        for (int i = 0; i <= 50; ++i)
        {
            count += record[i];
            if (i >= left && i <= right && count <= 0)
            {
                return false;
            }
            else if (i >= right)
            {
                break;
            }
        }
        return true;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     bool isCovered(vector<vector<int>> &ranges, int left, int right)
//     {
//         sort(ranges.begin(), ranges.end(), [](vector<int> &l, vector<int> &r)
//              { return l[0] < r[0]; });
//         vector<vector<int>> union_ranges;
//         for (auto r : ranges)
//         {
//             if (union_ranges.empty() || union_ranges.back().back() < r[0] - 1)
//             {
//                 union_ranges.push_back(r);
//             }
//             else
//             {
//                 union_ranges.back().back() = max(union_ranges.back().back(), r[1]);
//             }
//             if (union_ranges.back()[0] <= left && union_ranges.back()[1] >= right)
//             {
//                 return true;
//             }
//             else if (union_ranges.back()[0] > left)
//             {
//                 return false;
//             }
//         }
//         return false;
//     }
// };