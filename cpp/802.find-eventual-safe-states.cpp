/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    vector<int> record; // -1 not seen, 0 pass, 1 cycle, 2 terminal
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int width = graph.size();
        record = vector<int>(width, -1);
        vector<int> res;
        for (int i = 0; i != width; ++i)
        {
            if (helpler(graph, i) == 2)
            {
                res.push_back(i);
            }
        }
        return res;
    }
    int helpler(vector<vector<int>> &graph, int pos)
    {
        if (record[pos] == 0)
        {
            record[pos] = 1;
            return 1;
        }
        else if (record[pos] == 1 || record[pos] == 2)
        {
            return record[pos];
        }
        else
        {
            record[pos] = 0;
        }

        if (graph[pos].empty())
        {
            record[pos] = 2;
            return 2;
        }

        for (auto &&n : graph[pos])
        {
            if (record[n] == 1 || record[n] == 0)
            {
                record[pos] = 1;
                return 1;
            }
            else if (record[n] == -1)
            {
                record[n] = helpler(graph, n);
                if (record[n] == 1)
                {
                    record[pos] = 1;
                    return 1;
                }
            }
        }
        record[pos] = 2;
        return 2;
    }
};
// @lc code=end
