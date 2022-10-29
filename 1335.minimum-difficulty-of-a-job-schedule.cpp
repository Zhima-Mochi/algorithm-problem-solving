/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int w = jobDifficulty.size();
        if (w < d)
        {
            return -1;
        }
        vector<vector<int>> records(w, vector<int>(d + 1, 10000));
        records[0][d - 1] = jobDifficulty[0];
        int left_max = jobDifficulty[0];
        for (int i = 1; i != w; ++i)
        {
            left_max = max(left_max, jobDifficulty[i]);
            records[i][d - 1] = left_max;
            int m_val = jobDifficulty[i];
            for (int j = i - 1; j != -1; --j)
            {
                for (int k = 1; k != d; ++k)
                {
                    records[i][k - 1] = min(records[i][k - 1], records[j][k] + m_val);
                }
                m_val = max(m_val, jobDifficulty[j]);
            }
        }
        return records[w - 1][0];
    }
};
// @lc code=end
