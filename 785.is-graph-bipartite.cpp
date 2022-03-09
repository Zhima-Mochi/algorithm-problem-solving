/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> group_record;

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int width = graph.size();
        group_record = vector<int>(width);
        for (int i = 0; i != width; ++i)
        {
            if (group_record[i] == 0 && !helpler(graph, 1, i))
            {
                return false;
            }
        }
        return true;
    }
    bool helpler(vector<vector<int>> &graph, int group, int ind)
    {
        if (group_record[ind] != 0)
        {
            return group_record[ind] == group;
        }
        group_record[ind] = group;
        for (auto n : graph[ind])
        {
            if (!helpler(graph, -group, n))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
