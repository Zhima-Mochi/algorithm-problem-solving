/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res;
        res.reserve(n);
        if (n % 2)
        {
            res.push_back(0);
            --n;
        }
        n /= 2;
        while (n)
        {
            res.push_back(n);
            res.push_back(-n);
            --n;
        }
        return res;
    }
};
// @lc code=end
