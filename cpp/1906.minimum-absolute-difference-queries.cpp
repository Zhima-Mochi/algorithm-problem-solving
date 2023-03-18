/*
 * @lc app=leetcode id=1906 lang=cpp
 *
 * [1906] Minimum Absolute Difference Queries
 */
#include <vector>
using namespace std;
// @lc code=start
// t: O(w+q), s:O(w)
class Solution
{
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        int w = nums.size();
        vector<vector<int>> records;
        records.push_back(vector<int>(101));
        for (int i = 0; i != w; ++i)
        {
            records.push_back(records.back());
            records.back()[nums[i]] += 1;
        }
        vector<int> res;
        for (auto &q : queries)
        {
            auto record = records[q[1] + 1];
            int val = 100;
            int step = 0;
            for (int i = 1; i != 101; ++i)
            {
                ++step;
                if (record[i] - records[q[0]][i])
                {
                    if (val == 100)
                    {
                        val = -1;
                    }
                    else
                    {
                        if (val == -1)
                        {
                            val = step;
                        }
                        else
                        {
                            val = min(val, step);
                        }
                    }
                    step = 0;
                }
            }
            res.push_back(val);
        }
        return res;
    }
};
// @lc code=end
