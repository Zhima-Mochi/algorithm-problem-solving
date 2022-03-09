/*
 * @lc app=leetcode id=1389 lang=cpp
 *
 * [1389] Create Target Array in the Given Order
 */
#include <vector>
#include <list>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        list<int> ls;
        int width = nums.size();
        for (int i = 0; i != width; ++i)
        {
            ls.insert(next(ls.begin(), index[i]), nums[i]);
        }
        return vector<int>(ls.begin(), ls.end());
    }
};
// @lc code=end
