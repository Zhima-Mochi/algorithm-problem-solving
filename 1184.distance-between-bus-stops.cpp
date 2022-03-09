/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int sum_val = 0;
        int len = distance.size();
        for (int i = start; i != destination; ++i)
        {
            sum_val += distance[i];
            if (i == len - 1)
            {
                i = -1;
            }
        }
        int sum_val2 = 0;
        for (int i = start - 1; i != destination - 1; --i)
        {
            if (i < 0)
            {
                i += len;
            }
            sum_val2 += distance[i];
            if (sum_val2 > sum_val)
            {
                return sum_val;
            }
        }
        return sum_val2;
    }
};
// @lc code=end
