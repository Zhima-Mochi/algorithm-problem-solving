/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        vector<int> res = {1};
        while (res.size() != n)
        {
            vector<int> next_vec;

            for (auto &a : res)
            {
                if (2 * a <= n)
                {
                    next_vec.push_back(2 * a);
                }
            }
            for (auto &a : res)
            {
                if (2 * a - 1 <= n)
                {
                    next_vec.push_back(2 * a - 1);
                }
            }
            swap(res, next_vec);
        }
        return res;
    }
};
// @lc code=end
