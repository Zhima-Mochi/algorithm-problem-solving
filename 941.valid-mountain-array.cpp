/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int width = arr.size();
        if (width < 3)
        {
            return false;
        }
        int pos = 1;
        for (; pos != width; ++pos)
        {
            if (arr[pos] == arr[pos - 1])
            {
                return false;
            }
            else if (arr[pos] < arr[pos - 1])
            {
                break;
            }
        }
        if (pos == 1 || pos == width)
        {
            return false;
        }
        for (; pos != width; ++pos)
        {
            if (arr[pos] >= arr[pos - 1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
