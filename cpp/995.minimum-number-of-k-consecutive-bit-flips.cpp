/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        queue<int> records;
        int w = nums.size();
        int res = 0;
        for (int i = 0; i != w; ++i)
        {
            while (!records.empty() && records.front() < i)
            {
                records.pop();
            }
            int c = records.size() % 2 ? 1 : 0;
            if (nums[i] ^ c == 0)
            {
                if (w - i >= k)
                {
                    res += 1;
                    records.push(i + k - 1);
                }
                else
                {
                    return -1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
