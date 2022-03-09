/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int len = arr.size();
        int res = 1;
        bool is_upper_pos = true;
        int count = 1;
        for (int i = 1; i != len; ++i)
        {
            if (arr[i] > arr[i - 1])
            {
                if (is_upper_pos)
                {
                    res = max(res, count);
                    count = 2;
                }
                else
                {
                    ++count;
                    is_upper_pos = true;
                }
            }
            else if (arr[i] < arr[i - 1])
            {
                if (is_upper_pos)
                {
                    ++count;
                    is_upper_pos = false;
                }
                else
                {
                    res = max(res, count);
                    count = 2;
                }
            }
            else
            {
                res = max(res, count);
                count = 1;
            }
        }
        return max(res, count);
    }
};
// @lc code=end
