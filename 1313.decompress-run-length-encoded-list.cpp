/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> res;
        int len = nums.size();
        for (int i = 0; i != len; i += 2)
        {
            res.insert(res.end(), nums[i], nums[i + 1]);
        }
        return res;
    }
};
// @lc code=end
