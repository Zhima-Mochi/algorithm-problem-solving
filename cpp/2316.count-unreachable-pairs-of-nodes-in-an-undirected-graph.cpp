/*
 * @lc app=leetcode id=2316 lang=cpp
 *
 * [2316] Count Unreachable Pairs of Nodes in an Undirected Graph
 */
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<int> groups(n);
        for (int i = 0; i != n; ++i)
        {
            groups[i] = i;
        }
        function<int(int)> get_root = [&](int num)
        {
            if (groups[num] == num)
            {
                return num;
            }
            groups[num] = get_root(groups[num]);
            return groups[num];
        };
        for (auto &edge : edges)
        {
            auto l = get_root(edge[0]);
            auto r = get_root(edge[1]);
            groups[l] = r;
        }
        vector<int> g_arr;
        unordered_map<int, long long> g_cnt;
        for (int i = 0; i != n; ++i)
        {
            g_cnt[get_root(groups[i])] += 1;
        }
        long long res = 0;
        for (auto p : g_cnt)
        {
            res += (n - p.second) * p.second;
        }
        return res / 2;
    }
};
// @lc code=end
