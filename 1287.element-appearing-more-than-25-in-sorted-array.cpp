/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int len = arr.size();
        int window = len / 4;
        if (window == 0)
        {
            return arr[0];
        }
        for (int i = 0; i != len - window; ++i)
        {
            if (arr[i] == arr[i + window])
            {
                return arr[i];
            }
        }
        return arr[0];
    }
};
// @lc code=end
