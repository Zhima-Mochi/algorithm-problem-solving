/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        vector<bool> record_array(200001);
        auto len = candyType.size();
        size_t type_count = 0;
        for (auto &type : candyType)
        {
            if (record_array[type + 100000] == false)
            {
                record_array[type + 100000] = true;
                ++type_count;
            }
        }
        return min(len / 2, type_count);
    }
};
// @lc code=end
