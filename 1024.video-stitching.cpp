/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(time+len(clips)), s:O(time)
class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        vector<int> record(time + 1);
        for (auto &clip : clips)
        {
            if (clip[0] <= time)
            {
                record[clip[0]] = max(record[clip[0]], clip[1]);
            }
        }
        if (record[0] == 0)
        {
            return -1;
        }
        int res = 1;
        int current_end = record[0];
        int next_end = 0;
        for (int i = 0; i != time + 1; ++i)
        {
            if (current_end >= time)
            {
                break;
            }
            else if (i > next_end)
            {
                break;
            }
            else if (i > current_end)
            {
                ++res;
                current_end = next_end;
                next_end = max(next_end, record[i]);
            }
            else
            {
                next_end = max(next_end, record[i]);
            }
        }
        return current_end >= time ? res : next_end >= time ? res + 1
                                                            : -1;
    }
};
// @lc code=end
