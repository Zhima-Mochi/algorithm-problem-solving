/*
 * @lc app=leetcode id=2079 lang=cpp
 *
 * [2079] Watering Plants
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int cur_cp = capacity;
        int w = plants.size();
        int res = 0;
        for (auto i = 0; i != w; ++i)
        {
            ++res;
            if (cur_cp < plants[i])
            {
                res += 2 * i;
                cur_cp = capacity - plants[i];
            }
            else
            {
                cur_cp -= plants[i];
            }
        }
        return res;
    }
};
// @lc code=end
