/*
 * @lc app=leetcode id=1575 lang=cpp
 *
 * [1575] Count All Possible Routes
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int mod = 1000000007;
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        vector<vector<long long>> mem(101, vector<long long>(401));
        for (int i = 0; i != 401; ++i)
        {
            mem[finish][i] = 1;
        }
        int w_loc = locations.size();
        for (int i = 0; i != fuel; i++)
        {
            for (int j = 0; j != w_loc; j++)
            {
                if (mem[j][i] != 0)
                {
                    for (int k = 0; k != w_loc; k++)
                    {
                        if (j == k)
                        {
                            continue;
                        }
                        int used = abs(locations[j] - locations[k]);
                        if (i + used > fuel)
                        {
                            continue;
                        }
                        mem[k][i + used] += mem[j][i];
                        mem[k][i + used] %= mod;
                    }
                }
            }
        }
        return mem[start][fuel];
    }
};
// @lc code=end
