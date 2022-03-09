/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> stk;
        int cur = 0;
        int width = graph.size();
        vector<vector<int>> res;
        vector<int> current_line = {0};
        while (true)
        {
            if (!graph[cur].empty())
            {
                if (current_line.back() == width - 1)
                {
                    res.push_back(current_line);
                }
                stk.push_back(graph[cur]);
                cur = graph[cur].back();
                stk.back().pop_back();
                current_line.push_back(cur);
            }
            else if (!stk.empty())
            {
                if (current_line.back() == width - 1)
                {
                    res.push_back(current_line);
                }
                current_line.pop_back();
                while (!stk.empty() && stk.back().empty())
                {
                    stk.pop_back();
                    current_line.pop_back();
                }
                if (stk.empty())
                {
                    break;
                }
                cur = stk.back().back();
                stk.back().pop_back();
                current_line.push_back(cur);
            }
            else
            {
                if (current_line.back() == width - 1)
                {
                    res.push_back(current_line);
                }
                break;
            }
        }
        return res;
    }
};
// @lc code=end
