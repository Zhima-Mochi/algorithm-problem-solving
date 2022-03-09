/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (auto n : arr1)
        {
            auto lb = lower_bound(arr2.begin(), arr2.end(), n);
            if (lb == arr2.end())
            {
                if (n - *prev(lb) > d)
                {
                    ++res;
                }
            }
            else if (lb == arr2.begin())
            {
                if (*lb - n > d)
                {
                    ++res;
                }
            }
            else if (*lb - n > d && n - *prev(lb) > d)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end
