/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<int, int> group_record; // 0 or 1;
    unordered_map<int, vector<int>> dislike_relation;

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        for (auto &dis : dislikes)
        {
            dislike_relation[dis[0]].push_back(dis[1]);
            dislike_relation[dis[1]].push_back(dis[0]);
        }
        for (int i = 1; i != n + 1; ++i)
        {
            if (group_record.count(i))
            {
                continue;
            }
            if (!dfs_check_valid_group(i, 0))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs_check_valid_group(int idx, int gp)
    {
        if (group_record.count(idx))
        {
            return gp == group_record[idx];
        }
        group_record[idx] = gp;
        int counter_group = gp ^ 1;
        for (auto dis_idx : dislike_relation[idx])
        {
            if (!dfs_check_valid_group(dis_idx, counter_group))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
