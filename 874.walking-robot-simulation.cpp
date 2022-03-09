/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 */
#include <vector>
#include <unordered_set>
#include <string>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        vector<int> pos = {0, 0};
        unordered_set<string> uset;
        for (auto &elem : obstacles)
        {
            uset.insert(to_string(elem[0]) + ' ' + to_string(elem[1]));
        }
        bool forward = true;
        bool toVertical = true;
        int res = 0;
        for (auto &elem : commands)
        {
            if (elem == -1)
            {
                if (!toVertical)
                {
                    forward = !forward;
                }
                toVertical = !toVertical;
            }
            else if (elem == -2)
            {
                if (toVertical)
                {
                    forward = !forward;
                }
                toVertical = !toVertical;
            }
            else
            {
                if (toVertical && forward)
                {
                    while (elem--)
                    {
                        if (!uset.count(to_string(pos[0]) + ' ' + to_string(pos[1] + 1)))
                        {
                            ++pos[1];
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if (toVertical && !forward)
                {
                    while (elem--)
                    {
                        if (!uset.count(to_string(pos[0]) + ' ' + to_string(pos[1] - 1)))
                        {
                            --pos[1];
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else if (!toVertical && forward)
                {
                    while (elem--)
                    {
                        if (!uset.count(to_string(pos[0] + 1) + ' ' + to_string(pos[1])))
                        {
                            ++pos[0];
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    while (elem--)
                    {
                        if (!uset.count(to_string(pos[0] - 1) + ' ' + to_string(pos[1])))
                        {
                            --pos[0];
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            res = max(pos[0] * pos[0] + pos[1] * pos[1], res);
        }
        return res;
    }
};
// @lc code=end
