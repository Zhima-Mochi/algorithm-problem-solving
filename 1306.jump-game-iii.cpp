/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        vector<int> past_pos;
        int width = arr.size();
        int cur_pos = start;
        while (true)
        {
            if (cur_pos >= 0 && cur_pos < width && arr[cur_pos] >= 0)
            {
                if (arr[cur_pos] == 0)
                {
                    return true;
                }
                arr[cur_pos] *= -1;
                past_pos.push_back(cur_pos);
                cur_pos -= arr[cur_pos];
            }
            else if (!past_pos.empty())
            {
                cur_pos = past_pos.back() + arr[past_pos.back()];
                past_pos.pop_back();
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     bool canReach(vector<int> &arr, int start)
//     {
//         vector<int> past_pos;
//         int width = arr.size();
//         vector<bool> has_standed(width);
//         int cur_pos = start;
//         while (true)
//         {
//             if (cur_pos >= 0 && cur_pos < width && !has_standed[cur_pos])
//             {
//                 if (arr[cur_pos] == 0)
//                 {
//                     return true;
//                 }
//                 has_standed[cur_pos] = true;
//                 past_pos.push_back(cur_pos);
//                 cur_pos += arr[cur_pos];
//             }
//             else if (!past_pos.empty())
//             {
//                 cur_pos = past_pos.back() - arr[past_pos.back()];
//                 past_pos.pop_back();
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         return false;
//     }
// };