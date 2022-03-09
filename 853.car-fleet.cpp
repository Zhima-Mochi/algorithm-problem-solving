/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(n*log(n)), s:O(n)
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<int> idx_arr(n);
        for (int i = 0; i != n; ++i)
        {
            idx_arr[i] = i;
        }
        sort(idx_arr.begin(), idx_arr.end(), [&position](int l, int r)
             { return position[l] < position[r]; });
        int res = 0;
        double prev_time = 0;
        for (int i = n - 1; i != -1; --i)
        {
            double time = (1.0 * target - position[idx_arr[i]]) / speed[idx_arr[i]];
            if (time > prev_time)
            {
                ++res;
                prev_time = time;
            }
        }
        return res;
    }
};
// @lc code=end
