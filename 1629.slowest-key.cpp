/*
 * @lc app=leetcode id=1629 lang=cpp
 *
 * [1629] Slowest Key
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        char candidate = keysPressed[0];
        int d = releaseTimes[0];
        int len = releaseTimes.size();
        for (int i = 1; i != len; ++i)
        {
            if (releaseTimes[i] - releaseTimes[i - 1] > d)
            {
                candidate = keysPressed[i];
                d = releaseTimes[i] - releaseTimes[i - 1];
            }
            else if (releaseTimes[i] - releaseTimes[i - 1] == d)
            {
                candidate = max(candidate, keysPressed[i]);
            }
        }
        return candidate;
    }
};
// @lc code=end
