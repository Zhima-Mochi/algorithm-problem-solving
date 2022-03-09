/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        vector<int> vec;
        int third = INT_MIN;
        auto bound = nums.rend();
        for (auto cur = nums.rbegin(); cur != bound; ++cur)
        {
            if (*cur < third)
            {
                return true;
            }
            while (!vec.empty() && *cur > vec.back())
            {
                third = vec.back();
                vec.pop_back();
            }
            vec.push_back(*cur);
        }
        return false;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     bool find132pattern(vector<int> &nums)
//     {
//         auto cur = nums.begin();
//         vector<vector<int>> vec;
//         int min_val = *cur;
//         auto bound = nums.end();
//         while (cur != bound)
//         {
//             if (*cur < min_val)
//             {
//                 min_val = *cur;
//             }
//             else
//             {
//                 int max_val = *cur;
//                 while (!vec.empty())
//                 {
//                     if (vec.back()[0] > max_val)
//                     {
//                         break;
//                     }
//                     else if (vec.back()[0] == max_val)
//                     {
//                         max_val = vec.back()[1];
//                         vec.pop_back();
//                     }
//                     else if (vec.back()[1] > max_val)
//                     {
//                         return true;
//                     }
//                     else
//                     {
//                         vec.pop_back();
//                     }
//                 }
//                 vec.push_back({min_val, max_val});
//             }
//             ++cur;
//         }
//         return false;
//     }
// };