/*
 * @lc app=leetcode id=2492 lang=cpp
 *
 * [2492] Minimum Score of a Path Between Two Cities
 */
#include <vector>
#include <cmath>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n^2), s:O(n)
class Solution
{
public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<int> group(n + 1);
        vector<int> min_score = vector<int>(n + 1, __INT_MAX__);
        for (int i = 0; i < n; ++i)
        {
            group[i] = i;
        }
        function<int(int)> find_group = [&](int x)
        {
            if (group[x] == x)
            {
                return x;
            }
            group[x] = find_group(group[x]);
            return group[x];
        };
        for (auto &road : roads)
        {
            int a_group = find_group(road[0]);
            int b_group = find_group(road[1]);
            min_score[b_group] = min(min_score[a_group], min_score[b_group]);
            group[a_group] = b_group;
            min_score[b_group] = min(min_score[b_group], road[2]);
        }
        return min_score[find_group(n)];
    }
};
// @lc code=end
