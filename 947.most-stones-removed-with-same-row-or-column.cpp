/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
// n=len(stones), m=initial total color
// t:O(nlog(m)), o:O(m)
class Solution
{
    int constraint = 10001;
    unordered_map<int, int> color;
    int find_root_color(unordered_map<int, int> &color, int idx)
    {
        if (idx == color[idx])
        {
            return idx;
        }
        else
        {
            return color[idx] = find_root_color(color, color[idx]);
        }
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        int w = stones.size();
        for (int i = 0; i != w; ++i)
        {
            color[stones[i][0]] = stones[i][0];
            color[stones[i][1] + constraint] = stones[i][1] + constraint;
        }
        int diff_color_cnt = color.size();
        for (int i = 0; i != w; ++i)
        {
            int &col_root_color = color[find_root_color(color, stones[i][1] + constraint)];
            int row_root_color = color[find_root_color(color, stones[i][0])];
            if (col_root_color != row_root_color)
            {
                --diff_color_cnt;
            }
            col_root_color = row_root_color;
        }
        return w - diff_color_cnt;
    }
};
// @lc code=end
