/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> count;
        int result = 0;
        int len = nums1.size();
        for (int i = 0; i != len; ++i)
        {
            for (int j = 0; j != len; ++j)
            {
                ++count[nums1[i] + nums2[j]];
            }
        }
        for (int i = 0; i != len; ++i)
        {
            for (int j = 0; j != len; ++j)
            {
                result += count[-nums3[i] - nums4[j]];
            }
        }
        return result;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
//     {
//         unordered_map<int, int> count_1, count_2;
//         int result = 0;
//         int len = nums1.size();
//         for (int i = 0; i != len; ++i)
//         {
//             for (int j = 0; j != len; ++j)
//             {
//                 ++count_1[nums1[i] + nums2[j]];
//                 ++count_2[nums3[i] + nums4[j]];
//             }
//         }
//         for (auto i = count_1.begin(); i != count_1.end(); ++i)
//         {
//             if (count_2.count(-i->first))
//             {
//                 result += i->second * count_2[-i->first];
//             }
//         }

//         return result;
//     }
// };