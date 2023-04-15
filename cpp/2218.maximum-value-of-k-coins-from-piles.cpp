/*
 * @lc app=leetcode id=2218 lang=cpp
 *
 * [2218] Maximum Value of K Coins From Piles
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n*k*k) s:O(k)
class Solution
{
public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int w = piles.size();
        vector<int> records(k + 1, 0);
        for (int i = 1; i <= w; i++)
        {
            int current_width = piles[i - 1].size();
            for (int j = k; j >= 0; j--)
            {
                int current_coins = 0;
                for (int m = 0; m != j; m++)
                {
                    if (m == current_width)
                    {
                        break;
                    }
                    current_coins += piles[i - 1][m];
                    records[j] = max(records[j], records[j - m - 1] + current_coins);
                }
            }
        }
        return records[k];
    }
};
// @lc code=end
