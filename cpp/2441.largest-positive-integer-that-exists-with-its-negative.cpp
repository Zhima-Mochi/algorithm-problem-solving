/*
 * @lc app=leetcode id=2441 lang=cpp
 *
 * [2441] Largest Positive Integer That Exists With Its Negative
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int res = -1;
        unordered_set<int> s;
        for (auto n : nums)
        {
            if (s.count(-n))
            {
                if (res <= abs(n))
                {
                    res = abs(n);
                }
            }
            s.insert(n);
        }
        return res;
    }
};
// @lc code=end
