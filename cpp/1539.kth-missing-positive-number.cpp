/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int width = arr.size();
        if (arr[0] > k)
        {
            return k;
        }
        else
        {
            k -= (arr[0] - 1);
        }
        for (int i = 1; i != width; ++i)
        {
            if (k + arr[i - 1] < arr[i])
            {
                return k + arr[i - 1];
            }
            else
            {
                k -= arr[i] - arr[i - 1] - 1;
            }
        }
        return k + arr.back();
    }
};
// @lc code=end
