/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <vector>
// #include <unordered_map>
// #include <map>
#include <algorithm>
using namespace std;
// @lc code=start

class Solution
{
public:
    // map<int, short, greater<int>> negative_pair;
    // map<int, short> positive_pair;
    // int zero_count = 0;
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int len = nums.size();
        if (len < 3)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        if (0 < 3 * nums[0] || 0 > 3 * nums[len - 1])
        {
            return res;
        }
        for (int i = 0; i != len - 2 && nums[i] <= 0; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1, right = len - 1;
            while (left < right)
            {
                auto sum_val = nums[i] + nums[left] + nums[right];
                if (sum_val < 0)
                {
                    ++left;
                    while (left < right && nums[left - 1] == nums[left])
                    {
                        ++left;
                    }
                }
                else if (sum_val > 0)
                {
                    --right;
                    while (left < right && nums[right + 1] == nums[right])
                    {
                        --right;
                    }
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                    --right, ++left;
                    while (left < right && nums[left - 1] == nums[left])
                    {
                        ++left;
                    }
                    while (left < right && nums[right + 1] == nums[right])
                    {
                        --right;
                    }
                }
            }
        }
        return res;
    }
    // vector<vector<int>> res;

    // for (auto &n : nums)
    // {
    //     if (n < 0)
    //     {
    //         negative_pair[n] += 1;
    //     }
    //     else if (n > 0)
    //     {
    //         positive_pair[n] += 1;
    //     }
    //     else
    //     {
    //         zero_count++;
    //     }
    // }
    // if (zero_count >= 3)
    // {
    //     res.push_back(vector<int>{0, 0, 0});
    // }
    // if (positive_pair.size() == 0 || negative_pair.size() == 0)
    // {
    //     return res;
    // }
    // for (auto &pair : negative_pair)
    // {
    //     auto &cur_val = pair.first;
    //     if (zero_count)
    //     {
    //         if (positive_pair.find(-1 * cur_val) != positive_pair.end())
    //         {
    //             res.push_back(vector<int>{cur_val, 0, -1 * cur_val});
    //         }
    //     }
    //     auto upper_bound = positive_pair.lower_bound((-1 * cur_val) / 2);
    //     if ((*upper_bound).first * 2 < -1 * cur_val)
    //     {
    //         upper_bound++;
    //     }

    //     for (auto target_pos = positive_pair.begin(); target_pos != upper_bound; target_pos++)
    //     {
    //         auto target_val = (*target_pos).first;
    //         auto counter_val = (cur_val + target_val) * -1;
    //         if (positive_pair.find(counter_val) != positive_pair.end())
    //         {
    //             res.push_back(vector<int>{cur_val, target_val, counter_val});
    //         }
    //     }
    //     if (cur_val % 2 == 0)
    //     {
    //         auto counter_half_val = -1 * cur_val / 2;
    //         auto counter_half_pos = positive_pair.find(counter_half_val);
    //         if (counter_half_pos != positive_pair.end() && (*counter_half_pos).second >= 2)
    //         {
    //             res.push_back(vector<int>{cur_val, counter_half_val, counter_half_val});
    //         }
    //     }
    // }

    // for (auto &pair : positive_pair)
    // {
    //     auto &cur_val = pair.first;
    //     auto upper_bound = negative_pair.lower_bound((-1 * cur_val) / 2);
    //     if ((*upper_bound).first * 2 > -1 * cur_val)
    //     {
    //         upper_bound++;
    //     }

    //     for (auto target_pos = negative_pair.begin(); target_pos != upper_bound; target_pos++)
    //     {
    //         auto target_val = (*target_pos).first;
    //         auto counter_val = (cur_val + target_val) * -1;
    //         if (negative_pair.find(counter_val) != negative_pair.end())
    //         {
    //             res.push_back(vector<int>{cur_val, target_val, counter_val});
    //         }
    //     }
    //     if (cur_val % 2 == 0)
    //     {
    //         auto counter_half_val = -1 * cur_val / 2;
    //         auto counter_half_pos = negative_pair.find(counter_half_val);
    //         if (counter_half_pos != negative_pair.end() && (*counter_half_pos).second >= 2)
    //         {
    //             res.push_back(vector<int>{cur_val, counter_half_val, counter_half_val});
    //         }
    //     }
    // }

    // return res;
};
// @lc code=end
