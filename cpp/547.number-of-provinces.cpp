/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
// @lc code=start
// t:O(N^2*log(N)), s:O(N)
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int w = isConnected.size();
        vector<int> group_record(w);
        iota(group_record.begin(), group_record.end(), 0);
        function<int(int)> get_root_group_num = [&](int n)
        {
            if (group_record[n] == n)
            {
                return group_record[n];
            }
            return group_record[n] = get_root_group_num(group_record[n]);
        };
        for (int i = 0; i != w; ++i)
        {
            for (int j = i + 1; j != w; ++j)
            {
                if (isConnected[i][j])
                {
                    int g_1 = get_root_group_num(i);
                    int g_2 = get_root_group_num(j);
                    group_record[g_2] = g_1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            if (group_record[i] == i)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
