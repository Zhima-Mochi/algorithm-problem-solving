/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        int value = 1;
        vector<string> res;
        for (auto n : target)
        {
            while (value < n)
            {
                res.push_back("Push");
                res.push_back("Pop");
                ++value;
            }
            res.push_back("Push");
            ++value;
        }
        return res;
    }
};
// @lc code=end
