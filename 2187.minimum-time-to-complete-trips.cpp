/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        long long left = 1, right = static_cast<long long>(totalTrips) * *min_element(time.begin(), time.end());
        while (left < right)
        {
            long long mid = left + (right - left) / 2;
            long long trips = 0;
            for (auto t : time)
            {
                trips += mid / t;
            }
            if (trips < totalTrips)
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
