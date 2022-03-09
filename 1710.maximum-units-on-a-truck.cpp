/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        vector<int> units_count(1001);
        for (auto &bt : boxTypes)
        {
            units_count[bt[1]] += bt[0];
        }
        int res = 0;
        for (auto i = 1000; i != 0; --i)
        {
            if (units_count[i] > 0)
            {
                if (units_count[i] < truckSize)
                {
                    res += i * units_count[i];
                    truckSize -= units_count[i];
                }
                else
                {
                    res += i * truckSize;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end
