/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n), s:O(k)
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int res = 0;
        unordered_map<int, int> last_seen_pos;
        int w = nums.size();
        int current_min_pos = 0;
        int cur = 0;
        for (int i = 0; i != w; ++i)
        {
            last_seen_pos[nums[i]] = i;
            while (last_seen_pos[nums[current_min_pos]] != current_min_pos)
            {
                current_min_pos++;
            }
            if (last_seen_pos.size() == k)
            {
                res += (current_min_pos - cur) + 1;
            }
            else if (last_seen_pos.size() == k + 1)
            {
                last_seen_pos.erase(nums[current_min_pos]);
                current_min_pos += 1;
                cur = current_min_pos;
                while (last_seen_pos[nums[current_min_pos]] != current_min_pos)
                {
                    current_min_pos++;
                }
                res += (current_min_pos - cur) + 1;
            }
        }
        return res;
    }
};
// @lc code=end
