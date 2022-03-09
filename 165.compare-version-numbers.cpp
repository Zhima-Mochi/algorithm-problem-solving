/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        size_t left_pos = 0, right_pos = 0;
        while (left_pos != -1 || right_pos != -1)
        {
            size_t next_left_pos = -1;
            size_t next_right_pos = -1;
            size_t ver1 = 0, ver2 = 0;

            if (left_pos != -1)
            {
                next_left_pos = version1.find('.', left_pos);
                ver1 = stoi(version1.substr(left_pos, next_left_pos - left_pos));
            }
            if (right_pos != -1)
            {
                next_right_pos = version2.find('.', right_pos);
                ver2 = stoi(version2.substr(right_pos, next_right_pos - right_pos));
            }
            if (ver1 < ver2)
            {
                return -1;
            }
            else if (ver1 > ver2)
            {
                return 1;
            }
            else
            {
                left_pos = max(next_left_pos + 1, next_left_pos);
                right_pos = max(next_right_pos + 1, next_right_pos);
            }
        }
        return 0;
    }
};
// @lc code=end
