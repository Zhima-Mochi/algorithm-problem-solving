/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        vector<int> group_num(n);
        for (int i = 0; i != n; ++i)
        {
            group_num[i] = i;
        }
        for (auto &&edge : edges)
        {
            group_num[edge[0]] = group_num[get_root_group_num(group_num, edge[0])] = group_num[get_root_group_num(group_num, edge[1])];
        }
        return get_root_group_num(group_num, start) == get_root_group_num(group_num, end);
    }
    int get_root_group_num(vector<int> &group_num, int n)
    {
        if (group_num[n] != n)
        {
            return group_num[n] = get_root_group_num(group_num, group_num[n]);
        }
        else
        {
            return n;
        }
    }
};
// @lc code=end