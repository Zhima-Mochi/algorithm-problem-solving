/*
 * @lc app=leetcode id=1719 lang=cpp
 *
 * [1719] Number Of Ways To Reconstruct A Tree
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    int checkWays(vector<vector<int>> &pairs)
    {
        unordered_map<int, unordered_set<int>> neighbors;
        for (auto &pair : pairs)
        {
            neighbors[pair[0]].insert(pair[1]);
            neighbors[pair[1]].insert(pair[0]);
        }
        int kinds = neighbors.size();
        int max_size_kind = 0;
        int max_size = 0;
        vector<int> node;
        for (auto &p : neighbors)
        {
            node.push_back(p.first);
        }
        sort(node.begin(), node.end(), [&](int l, int r)
             { return neighbors[l].size() < neighbors[r].size(); });
        if (neighbors[node.back()].size() + 1 != kinds)
        {
            return 0;
        }

        int res = 1;
        int w = node.size();
        for (int i = 0; i != w - 1; ++i)
        {
            bool flag = false;
            for (int j = i + 1; j != w; ++j)
            {
                if (neighbors[node[j]].count(node[i]))
                {
                    flag = true;
                    for (auto n : neighbors[node[i]])
                    {
                        if (n != node[j] && !neighbors[node[j]].count(n))
                        {
                            return 0;
                        }
                    }
                    if (neighbors[node[j]].size() == neighbors[node[i]].size())
                    {
                        res = 2;
                    }
                    break;
                }
            }
            if (!flag)
            {
                return false;
            }
        }
        return res;
    }
};
// @lc code=end
