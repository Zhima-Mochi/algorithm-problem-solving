/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result =0;
        for(auto & num:nums){
            result^=num;
        }
        return result;
    }
};
// @lc code=end
