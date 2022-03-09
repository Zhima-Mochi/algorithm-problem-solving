/*
 * @lc app=leetcode id=1093 lang=cpp
 *
 * [1093] Statistics from a Large Sample
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<double> sampleStats(vector<int> &count)
    {
        vector<double> res(5, 0);
        res[0] = -1;
        res[3] = -1;
        double total_count = 0;
        int mode_cnt = 0;
        for (int i = 0; i != 256; ++i)
        {
            if (count[i])
            {
                if (res[0] == -1)
                {
                    res[0] = i;
                }
                res[1] = i;
                total_count += count[i];
                if (count[i] > mode_cnt)
                {
                    res[4] = i;
                    mode_cnt = count[i];
                }
            }
        }
        int medium_counter = total_count;
        int prev = -1;
        for (int i = 0; i != 256; ++i)
        {
            if (count[i])
            {
                res[2] += count[i] / total_count * i;
                if (medium_counter == 0)
                {
                    res[3] = (i + prev) / 2.0;
                }
                if (res[3] == -1 && medium_counter < count[i] * 2)
                {
                    res[3] = i;
                }
                medium_counter -= count[i] * 2;
                prev = i;
            }
        }
        return res;
    }
};
// @lc code=end
