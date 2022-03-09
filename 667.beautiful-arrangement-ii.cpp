/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> res(n + 1);
        if (k > 1)
        {
            for (int i = 0; i < 2 * k && i < n; i += 2)
            {
                res[i] = i / 2 + 1;
                res[i + 1] = k + 2 - res[i];
            }
            for (int i = k + 1; i != n; ++i)
            {
                res[i] = i + 1;
            }
        }
        else
        {
            for (int i = 0; i != n; ++i)
            {
                res[i] = i + 1;
            }
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
