/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result(1);
        for (auto & num : nums)
        {
            auto len=result.size();
            //Do not use "for(auto elem: result)", since memory allocation of vector might happen.
            for (size_t i=0;i!=len;i++)
            {
                auto elem=result[i];
                elem.push_back(num);
                result.push_back(elem);
            }
        }
        return result;
    }
};
// @lc code=end
