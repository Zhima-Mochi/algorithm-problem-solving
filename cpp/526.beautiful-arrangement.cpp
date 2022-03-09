/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countArrangement(int n)
    {
        int res = 0;
        vector<bool> used(n);
        backtrack(res, n, used);
        return res;
    }
    void backtrack(int &res, int n, vector<bool> &used)
    {
        if (n == 0)
        {
            ++res;
            return;
        }
        int index = 1;
        for (auto val : used)
        {
            if (!val && (!(n % index) || !(index % n)))
            {
                val = true;
                backtrack(res, n - 1, used);
                val = false;
            }
            ++index;
        }
    }
};
// @lc code=end
