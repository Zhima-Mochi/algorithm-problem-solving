/*
 * @lc app=leetcode id=1434 lang=cpp
 *
 * [1434] Number of Ways to Wear Different Hats to Each Other
 */
#include <vector>
#include <unordered_map>
#include <map>
#include <functional>
using namespace std;
// @lc code=start
int mod = 1000000007;
class Solution
{
public:
    int numberWays(vector<vector<int>> &hats)
    {
        int w = hats.size();
        map<int, int> hatIndexTrans;
        for (auto &h : hats)
        {
            for (auto n : h)
            {
                hatIndexTrans[n] = 0;
            }
        }
        int newIdx = 1;
        for (auto &p : hatIndexTrans)
        {
            p.second = newIdx++;
        }
        int hat_w = hatIndexTrans.size();
        vector<vector<int>> hat_prefered_people(hat_w + 1);
        for (int i = 0; i != w; ++i)
        {
            for (auto h : hats[i])
            {
                hat_prefered_people[hatIndexTrans[h]].push_back(i);
            }
        }
        vector<vector<int>> memo(hat_w + 1, vector<int>(1 << w));
        memo[0][0] = 1;
        for (int i = 1; i <= hat_w; ++i)
        {
            for (int j = 0; j != (1 << w); ++j)
            {
                memo[i][j] = memo[i - 1][j];
                for (auto people : hat_prefered_people[i])
                {
                    if (j & (1 << people))
                    {
                        memo[i][j] += memo[i - 1][j ^ (1 << people)];
                        memo[i][j] %= mod;
                    }
                }
            }
        }
        return memo[hat_w][(1 << w) - 1];
    }
};
// @lc code=end
