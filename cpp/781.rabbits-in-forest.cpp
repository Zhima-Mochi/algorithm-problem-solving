/*
 * @lc app=leetcode id=781 lang=cpp
 *
 * [781] Rabbits in Forest
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        vector<int> num_declaimed_count(1001);
        for (auto a : answers)
        {
            ++num_declaimed_count[a];
        }
        int res = 0;
        for (int i = 0; i != 1001; ++i)
        {
            if (num_declaimed_count[i] > 0)
            {
                res += (i + 1) * (num_declaimed_count[i] / (i + 1));
                if (num_declaimed_count[i] % (i + 1))
                {
                    res += (i + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end
