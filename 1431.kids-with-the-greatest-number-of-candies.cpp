/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max_val = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        res.reserve(candies.size());
        for (auto n : candies)
        {
            if (n + extraCandies >= max_val)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};
// @lc code=end
