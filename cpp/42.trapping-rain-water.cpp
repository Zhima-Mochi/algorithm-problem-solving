/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int max_left = 0, max_right = 0;
        while (left < right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] <= max_left)
                {
                    res += max_left - height[left];
                }
                else
                {
                    max_left = height[left];
                }
                ++left;
            }
            else
            {
                if (height[right] <= max_right)
                {
                    res += max_right - height[right];
                }
                else
                {
                    max_right = height[right];
                }
                --right;
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int res = 0;
//         stack<int> st;
//         int len = height.size();
//         for (int pos = 0; pos != len; ++pos)
//         {
//             if (!st.empty() && height[pos] >= height[st.top()])
//             {
//                 auto pre_local_peak = height[st.top()];
//                 for (int i = st.top() + 1; i != pos; ++i)
//                 {
//                     res += pre_local_peak - height[i];
//                 }
//                 st.pop();
//                 while (!st.empty() && height[pos] >= height[st.top()])
//                 {
//                     res += (pos - st.top() - 1) * (height[st.top()] - pre_local_peak);
//                     pre_local_peak = height[st.top()];
//                     st.pop();
//                 }
//                 if (!st.empty())
//                 {
//                     res += (height[pos] - pre_local_peak) * (pos - st.top() - 1);
//                 }
//                 st.push(pos);
//             }
//             else
//             {
//                 st.push(pos);
//             }
//         }
//         return res;
//     }
// };