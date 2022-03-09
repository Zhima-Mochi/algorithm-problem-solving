/*
 * @lc app=leetcode id=2032 lang=cpp
 *
 * [2032] Two Out of Three
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
    {
        vector<int> record(101);
        vector<int> res;
        for (auto &&n : nums1)
        {
            record[n] |= 1;
        }
        for (auto &&n : nums2)
        {
            if (record[n] == 1)
            {
                res.push_back(n);
            }
            record[n] |= 2;
        }
        for (auto &&n : nums3)
        {
            if (record[n] == 1 || record[n] == 2)
            {
                res.push_back(n);
            }
            record[n] |= 4;
        }
        return res;
    }
};
// @lc code=end
