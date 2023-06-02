/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
// @lc code=start
// t:O(n^3), s:O(n^2)
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int w = cuts.size();
        vector<vector<int>> records(w, vector<int>(w));
        for (int j = 2; j != w; ++j)
        {
            for (int i = 0; i + j != w; ++i)
            {
                records[i][i + j] = (cuts[i + j] - cuts[i]) * j;
                for (int k = i + 1; k != i + j; ++k)
                {
                    records[i][i + j] = min(records[i][i + j], (cuts[i + j] - cuts[i]) + records[i][k] + records[k][i + j]);
                }
            }
        }
        return records[0][w - 1];
    }
};
// @lc code=end
