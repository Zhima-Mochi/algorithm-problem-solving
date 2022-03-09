/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> res;
        if (turnedOn > 8)
        {
            return res;
        }
        queue<int> pre_res;
        pre_res.push(0);
        while (turnedOn)
        {
            int len = pre_res.size();
            for (int i = 0; i != len; ++i)
            {
                auto current = pre_res.front();
                pre_res.pop();
                for (int j = 0; j != 6; ++j)
                {
                    if (current > 63)
                    {
                        break;
                    }
                    if ((current & (1 << j)) == 0)
                    {
                        if ((current | (1 << j)) < 60)
                        {
                            pre_res.push(current + (1 << j));
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                for (int k = 0; k != 4; ++k)
                {
                    if ((current & (1 << k + 6)) == 0)
                    {
                        if ((current | (1 << k + 6)) < 12 * 64)
                        {
                            pre_res.push(current + (1 << k + 6));
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
            --turnedOn;
        }

        while (!pre_res.empty())
        {
            res.push_back(to_string(pre_res.front() / 64) + ((pre_res.front() & 63) < 10 ? ":0" : ":") + to_string(pre_res.front() & 63));
            pre_res.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
