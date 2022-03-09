/*
 * @lc app=leetcode id=2114 lang=cpp
 *
 * [2114] Maximum Number of Words Found in Sentences
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int res = 0;
        for (auto s : sentences)
        {
            int cnt = 0;
            for (auto c : s)
            {
                if (isblank(c))
                {
                    ++cnt;
                }
            }
            res = max(cnt + 1, res);
        }
        return res;
    }
};
// @lc code=end
