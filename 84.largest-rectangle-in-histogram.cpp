/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(N), s:O(N)
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0;
        vector<pair<int, int>> st;
        int w = heights.size();
        for (int i = 0; i != w; ++i)
        {
            if (!st.empty())
            {
                int replaced_idx = i;
                int max_height_idx = st.back().second;
                while (!st.empty() && st.back().first > heights[i])
                {
                    res = max(res, (max_height_idx - st.back().second + 1) * st.back().first);
                    replaced_idx = st.back().second;
                    st.pop_back();
                }
                st.push_back({heights[i], replaced_idx});
            }
            st.push_back({heights[i], i});
        }
        if (!st.empty())
        {
            int max_height_idx = st.back().second;
            while (!st.empty())
            {
                res = max(res, (max_height_idx - st.back().second + 1) * st.back().first);
                st.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end
