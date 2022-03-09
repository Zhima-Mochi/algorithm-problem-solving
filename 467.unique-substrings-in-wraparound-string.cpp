/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        vector<int> accum_count(26);
        int len = p.size();
        int pos = 0;
        while (pos != len)
        {
            int start_alpha = p[pos] - 'a';
            int count = 1;
            ++pos;
            while (pos != len && (p[pos] - p[pos - 1] == 1 || p[pos] == 'a' && p[pos - 1] == 'z'))
            {
                ++count;
                ++pos;
            }
            for (auto alpha = start_alpha, compare_count = 0; count && compare_count != 26; ++alpha, alpha %= 26, ++compare_count)
            {
                accum_count[alpha] = max(accum_count[alpha], count--);
            }
        }
        return accumulate(accum_count.begin(), accum_count.end(), 0);
    }
};
// @lc code=end
