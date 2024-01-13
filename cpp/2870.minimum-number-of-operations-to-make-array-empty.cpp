/*
 * @lc app=leetcode id=2870 lang=cpp
 *
 * [2870] Minimum Number of Operations to Make Array Empty
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (auto num : nums)
        {
            count[num]++;
        }
        int ans = 0;
        for (auto &[_, v] : count)
        {
            if (v % 3 == 0)
            {
                ans += v / 3;
            }
            else if (v % 3 == 1)
            {
                if (v < 3)
                {
                    return -1;
                }
                ans += v / 3 + 1;
            }
            else if (v % 3 == 2)
            {
                ans += v / 3 + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
