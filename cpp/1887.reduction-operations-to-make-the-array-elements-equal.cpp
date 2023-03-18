/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        vector<int> records(50001);
        for (auto n : nums)
        {
            records[n]++;
        }
        int count = 0;
        int res = 0;
        for (int i = 50000; i != 0; --i)
        {
            if (records[i] != 0)
            {
                res += count;
                count += records[i];
            }
        }
        return res;
    }
};
// @lc code=end
