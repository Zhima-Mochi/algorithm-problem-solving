/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(len(quan)log(m)), s:O(1)
class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int m = *max_element(quantities.begin(), quantities.end());
        int left = 1, right = m;
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            int cnt = 0;
            for (auto q : quantities)
            {
                cnt += (q + (mid - 1)) / mid;
                if (cnt > n)
                {
                    break;
                }
            }
            if (cnt > n)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
