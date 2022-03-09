/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> cnt;
        int h = matrix.size();
        int w = matrix[0].size();
        for (int i = 0; i != h; ++i)
        {
            string s1, s2;
            for (int j = 0; j != w; ++j)
            {
                if (matrix[i][j])
                {
                    s1.push_back('1');
                    s2.push_back('0');
                }
                else
                {
                    s1.push_back('0');
                    s2.push_back('1');
                }
            }
            ++cnt[s1];
            ++cnt[s2];
        }
        int res = 0;
        for (auto &p : cnt)
        {
            res = max(res, p.second);
        }
        return res;
    }
};
// @lc code=end
