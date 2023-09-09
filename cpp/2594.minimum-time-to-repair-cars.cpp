/*
 * @lc app=leetcode id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
// t:O(nlogn), s:O(1)
class Solution
{
public:
    using ll = long long;
    long long repairCars(vector<int> &ranks, int cars)
    {
        ll left = 1, right = 1ll * ranks[0] * cars * cars;
        auto pass = [&](ll m)
        {
            ll cnt = 0;
            for (auto rank : ranks)
            {
                cnt += sqrt(m / rank);
            }
            return cnt >= cars;
        };
        while (left < right)
        {
            ll mid = left + right >> 1;
            if (pass(mid))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
