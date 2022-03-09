/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        int even_val = 0;
        for (auto &n : nums)
        {
            if (n % 2 == 0)
            {
                even_val += n;
            }
        }
        vector<int> res;
        res.reserve(queries.size());
        for (auto &q : queries)
        {
            if (nums[q[1]] % 2 == 0)
            {
                if (q[0] % 2 == 0)
                {
                    nums[q[1]] += q[0];
                    even_val += q[0];
                }
                else
                {
                    even_val -= nums[q[1]];
                    nums[q[1]] += q[0];
                }
            }
            else
            {
                if (q[0] % 2 == 0)
                {
                    nums[q[1]] += q[0];
                }
                else
                {
                    nums[q[1]] += q[0];
                    even_val += nums[q[1]];
                }
            }
            res.push_back(even_val);
        }
        return res;
    }
};
// @lc code=end
