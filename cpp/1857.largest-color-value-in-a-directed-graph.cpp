/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> connection;
        unordered_set<int> is_not_head;
        for (auto &edge : edges)
        {
            connection[edge[0]].push_back(edge[1]);
            is_not_head.insert(edge[1]);
        }
        int w = colors.size();
        array<array<int, 27>, 100001> records;
        for (int i = 0; i != w; ++i)
        {
            for (int j = 0; j != 27; ++j)
            {
                records[i].fill(0);
            }
        }
        unordered_set<int> seen;
        unordered_set<int> has_picked;
        int res = -1;
        function<bool(int)> dp = [&](int node)
        {
            has_picked.insert(node);
            seen.insert(node);
            records[node][colors[node] - 'a'] = 1;
            records[node][26] = 1;
            for (auto next_node : connection[node])
            {
                if (seen.count(next_node))
                {
                    return false;
                }
                if (records[next_node][26] == 0)
                {
                    auto ok = dp(next_node);
                    if (!ok)
                    {
                        return false;
                    }
                }
                for (int i = 0; i != 26; ++i)
                {
                    records[node][i] = max(records[node][i], records[next_node][i] + (i == colors[node] - 'a' ? 1 : 0));
                }
            }
            seen.erase(node);
            return true;
        };
        for (int i = 0; i != w; ++i)
        {
            if (is_not_head.count(i))
            {
                continue;
            }
            auto ok = dp(i);
            if (!ok)
            {
                return -1;
            }
            for (int j = 0; j != 26; ++j)
            {
                res = max(res, records[i][j]);
            }
        }
        if (has_picked.size() != w)
        {
            return -1;
        }
        return res;
    }
};
// @lc code=end
