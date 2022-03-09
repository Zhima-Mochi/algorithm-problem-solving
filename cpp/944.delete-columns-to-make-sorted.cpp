/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int count = 0;
        int width = strs[0].size();
        for (int i = 0; i != width; ++i)
        {
            for (auto iter = next(strs.begin()), iterEnd = strs.end(); iter != iterEnd; ++iter)
            {
                if ((*iter)[i] < (*prev(iter))[i])
                {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};
// @lc code=end
