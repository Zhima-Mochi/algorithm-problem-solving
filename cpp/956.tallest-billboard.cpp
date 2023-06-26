/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        int w = rods.size();
        vector<int> records(5001, -1), temp(5001, -1);
        records[0] = 0;
        for (int i = 0; i != w; ++i)
        {
            for (int j = 0; j != 5001; ++j)
            {
                if (records[j] == -1)
                {
                    continue;
                }
                temp[j] = max(temp[j], records[j]);
                if (j >= rods[i])
                {
                    temp[j - rods[i]] = max(temp[j - rods[i]], records[j] + rods[i]);
                }
                else
                {
                    temp[rods[i] - j] = max(temp[rods[i] - j], records[j] + j);
                }
                temp[j + rods[i]] = max(temp[j + rods[i]], records[j]);
            }
            swap(temp, records);
        }
        return records[0];
    }
};
// @lc code=end
