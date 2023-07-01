/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSquarefulPerms(vector<int> &nums)
    {
        int w = nums.size();
        unordered_map<string, int> seen;
        queue<pair<string, int>> q;
        q.push({"", 0});
        int res = 0;
        while (!q.empty())
        {
            auto [str, used] = q.front();
            q.pop();
            if (used == (1 << w) - 1)
            {
                res += 1;
                continue;
            }
            for (int i = 0; i != w; ++i)
            {
                if (used & (1 << i))
                {
                    continue;
                }
                if (str == "" || is_square(seen[str] + nums[i]))
                {
                    string next_str = str + ',' + to_string(nums[i]);
                    if (seen.count(next_str))
                    {
                        continue;
                    }
                    seen[next_str] = nums[i];
                    q.push({next_str, used | (1 << i)});
                }
            }
        }
        return res;
    }
    bool is_square(int val)
    {
        int root = sqrt(val);
        return root * root == val;
    }
};
// @lc code=end
