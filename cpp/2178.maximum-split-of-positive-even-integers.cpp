/*
 * @lc app=leetcode id=2178 lang=cpp
 *
 * [2178] Maximum Split of Positive Even Integers
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> res;
        if (finalSum % 2)
        {
            return res;
        }
        finalSum /= 2;
        long long cur = 1;
        while (finalSum)
        {
            if (finalSum - cur > cur)
            {
                res.push_back(2 * cur);
                finalSum -= cur;
                cur++;
            }
            else
            {
                res.push_back(2 * finalSum);
                finalSum = 0;
            }
        }
        return res;
    }
};
// @lc code=end
