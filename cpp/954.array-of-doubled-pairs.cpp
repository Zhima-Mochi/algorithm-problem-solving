/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        int len = arr.size();
        if (len == 0)
        {
            return true;
        }
        sort(arr.begin(), arr.end());
        int right = len - 1;
        int left = right;
        if (arr[right] > 0 && arr[right] % 2 || arr[0] < 0 && arr[0] % 2)
        {
            return false;
        }
        while (right >= 0 && arr[right] > 0)
        {
            if (left < 0)
            {
                return false;
            }
            if (arr[left] * 2 > arr[right])
            {
                --left;
            }
            else if (arr[left] * 2 == arr[right])
            {
                arr[left] = -100000;
                --left, --right;
                while (right >= 0 && arr[right] == -100000)
                {
                    --right;
                }
            }
            else
            {
                return false;
            }
        }
        while (right >= 0 && arr[right] == 0)
        {
            --left;
            if (left < 0)
            {
                return false;
            }
            if (arr[left] != 0)
            {
                return false;
            }
            else
            {
                right -= 2;
                left = right;
            }
        }
        while (right >= 0)
        {
            if (left < 0)
            {
                return false;
            }
            if (arr[left] > arr[right] * 2)
            {
                --left;
            }
            else if (arr[left] == arr[right] * 2)
            {
                arr[left] = -100000;
                --left, --right;
                while (right >= 0 && arr[right] == -100000)
                {
                    --right;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
