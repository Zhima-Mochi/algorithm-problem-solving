/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> seen_count;
        int res = 0;
        for (auto n : nums)
        {
            res += seen_count[n]++;
        }
        return res;
    }
};
// @lc code=end
