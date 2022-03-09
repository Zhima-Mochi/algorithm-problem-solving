/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        vector<int> count(1001);
        for (auto n : target)
        {
            ++count[n];
        }
        for (auto n : arr)
        {
            --count[n];
            if (count[n] == -1)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
