/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findKthNumber(int m, int n, int k)
    {
        int left = 1, right = m * n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int smaller_num = 0;
            int equal_num = 0;
            for (int i = 1; i <= m; ++i)
            {
                if (mid < i)
                {
                    break;
                }
                smaller_num += min(mid / i, n);
                if (mid % i == 0 && i * n >= mid)
                {
                    smaller_num -= 1;
                    equal_num += 1;
                }
            }
            if (smaller_num < k && smaller_num + equal_num >= k)
            {
                return mid;
            }
            else if (smaller_num + equal_num < k)
            {
                left = mid + 1;
            }
            else if (smaller_num >= k)
            {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
