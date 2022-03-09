/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int len = arr.size();
        int left = len - 1, right = left;
        for (int i = 0; i != len; ++i)
        {
            if (!arr[i])
            {
                ++right;
            }
        }
        while (left != right)
        {
            if (arr[left])
            {
                if (right < len)
                {
                    arr[right] = arr[left];
                }
            }
            else
            {
                if (right < len)
                {
                    arr[right] = 0;
                }
                --right;
                if (right < len)
                {
                    arr[right] = 0;
                }
            }
            --left, --right;
        }
    }
};
// @lc code=end
