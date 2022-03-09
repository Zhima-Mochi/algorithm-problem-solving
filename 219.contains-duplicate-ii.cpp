/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int width = nums.size();
        int bound = min(width, k + 1);
        if (bound == width)
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i != bound - 1; ++i)
            {
                if (nums[i] == nums[i + 1])
                {
                    return true;
                }
            }
            return false;
        }
        vector<pair<int, short>> vec;
        for (int i = 0; i != width; ++i)
        {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i != width - 1; ++i)
        {
            if (vec[i].first == vec[i + 1].first && vec[i + 1].second - vec[i].second <= k)
            {
                return true;
            }
        }
        return false;
        // int width = nums.size();
        // int bound = min(width, k + 1);
        // if (bound == width)
        // {
        //     sort(nums.begin(), nums.end());
        //     for (int i = 0; i != bound - 1; ++i)
        //     {

        //         if (nums[i] == nums[i + 1])
        //         {
        //             return true;
        //         }
        //     }
        //     return false;
        // }
        // unordered_map<int, short> mp;
        // for (int i = 0; i != width; ++i)
        // {
        //     if (mp.count(nums[i]))
        //     {
        //         if (i - mp[nums[i]] <= k)
        //         {
        //             return true;
        //         }
        //     }
        //     mp[nums[i]] = i;
        // }
        // return false;
    }
};
// @lc code=end
