/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */
#include <vector>
#include <unordered_map>
#include <queue>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(n^2) s:O(n^2)
class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int records[101][101];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                records[i][j] = 0;
            }
        }

        int w = group.size();
        records[n][0] = 1;
        for (int i = 0; i < w; i++)
        {
            int temp[101][101];
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= 100; k++)
                {
                    temp[j][k] = records[j][k];
                }
            }
            int cost = group[i];
            int benefit = profit[i];
            for (int j = n; j >= cost; j--)
            {
                for (int k = 0; k <= 100; k++)
                {
                    if (temp[j][k] > 0)
                    {
                        records[j - cost][min(100, k + benefit)] += temp[j][k];
                        records[j - cost][min(100, k + benefit)] %= 1000000007;
                    }
                }
            }
        }
        long long res = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = minProfit; j <= 100; j++)
            {
                res += records[i][j];
            }
            res %= 1000000007;
        }
        return res;
    }
};
// @lc code=end
