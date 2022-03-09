/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> freq(2001);
        for (auto n : arr)
        {
            ++freq[n + 1000];
        }
        vector<bool> seen_freq(1001);
        for (auto n : freq)
        {
            if (n != 0)
            {
                if (seen_freq[n])
                {
                    return false;
                }
                else
                {
                    seen_freq[n] = true;
                }
            }
        }
        return true;
    }
};
// @lc code=end
