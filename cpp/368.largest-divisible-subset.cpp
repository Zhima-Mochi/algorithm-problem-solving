/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, short> connect_count;
        unordered_map<int, int> next_val_map;
        int head = nums.back();
        connect_count[head] = 1;
        for (auto cur = next(nums.rbegin()); cur != nums.rend(); ++cur)
        {
            int forward_connect_num = 1;
            int val = *cur;
            for (auto i = prev(cur);; --i)
            {
                auto prev_val = *i;
                if (prev_val % val == 0)
                {
                    if (connect_count[prev_val] + 1 > forward_connect_num)
                    {
                        forward_connect_num = connect_count[prev_val] + 1;
                        next_val_map[val] = prev_val;
                    }
                }
                if (i == nums.rbegin())
                {
                    break;
                }
            }

            connect_count[val] = forward_connect_num;
            if (forward_connect_num > connect_count[head])
            {
                head = val;
            }
        }
        vector<int> res;
        while (next_val_map.count(head))
        {
            res.push_back(head);
            head = next_val_map[head];
        }
        res.push_back(head);
        return res;
    }
};
// @lc code=end
