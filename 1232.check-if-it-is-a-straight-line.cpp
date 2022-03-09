/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int len = coordinates.size();
        vector<int> prev = {coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]};
        for (int i = 1; i != len; ++i)
        {
            vector<int> current_vector = {coordinates[i][0] - coordinates[i - 1][0], coordinates[i][1] - coordinates[i - 1][1]};
            if (current_vector[1] * prev[0] != current_vector[0] * prev[1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
