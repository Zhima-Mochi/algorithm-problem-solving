/*
 * @lc app=leetcode id=2023 lang=cpp
 *
 * [2023] Number of Pairs of Strings With Concatenation Equal to Target
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int numOfPairs(vector<string> &nums, string target)
    {
        unordered_map<string, int> um;
        for (auto &num : nums)
        {
            um[num] += 1;
        }
        int res = 0;
        for (auto &[head, cnt] : um)
        {
            if (head.size() >= target.size() || head != target.substr(0, head.size()))
            {
                continue;
            }
            string tail = target.substr(head.size());
            if (head == tail)
            {
                res += um[head] * (um[head] - 1);
            }
            else
            {
                res += um[head] * um[tail];
            }
        }
        return res;
    }
};
// @lc code=end
