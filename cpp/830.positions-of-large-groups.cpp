/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int start_index = 0;
        vector<vector<int>> res;
        s.append("酷");
        int width = s.size();
        for (int i = 1; i < width; ++i)
        {
            if (s[i] != s[i - 1])
            {
                if (i - start_index >= 3)
                {
                    res.push_back({start_index, i - 1});
                }
                start_index = i;
            }
        }
        return res;
    }
};
// @lc code=end
