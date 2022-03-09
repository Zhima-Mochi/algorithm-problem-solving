/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        unordered_map<long, long> umap;
        int len = nums.size();
        for (int i = 0; i != k + 1 && i != len; ++i)
        {
            auto bucket = nums[i] / (static_cast<long>(t) + 1) - (nums[i] < 0);
            if (umap.count(bucket))
            {
                return true;
            }
            if (umap.count(bucket - 1))
            {
                if (nums[i] - umap[bucket - 1] <= t)
                {
                    return true;
                }
            }
            if (umap.count(bucket + 1))
            {
                if (umap[bucket + 1] - nums[i] <= t)
                {
                    return true;
                }
            }
            umap[bucket] = nums[i];
        }
        for (int i = k + 1; i < len; ++i)
        {
            auto prev_k_bucket = nums[i - (k + 1)] / (static_cast<long>(t) + 1) - (nums[i - (k + 1)] < 0);
            umap.erase(prev_k_bucket);

            auto bucket = nums[i] / (static_cast<long>(t) + 1) - (nums[i] < 0);
            if (umap.count(bucket))
            {
                return true;
            }
            if (umap.count(bucket - 1))
            {
                if (nums[i] - umap[bucket - 1] <= t)
                {
                    return true;
                }
            }
            if (umap.count(bucket + 1))
            {
                if (umap[bucket + 1] - nums[i] <= t)
                {
                    return true;
                }
            }
            umap[bucket] = nums[i];
        }
        return false;
    }
};
// @lc code=end

//O(n log k)
// class Solution
// {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
//     {
//         if (k == 0)
//         {
//             return false;
//         }
//         set<long> mset;
//         int len = nums.size();
//         for (int i = 0; i != k + 1 && i != len; ++i)
//         {
//             auto insert_pair = mset.insert(nums[i]);
//             if (insert_pair.second == false)
//             {
//                 return true;
//             }
//             else
//             {
//                 auto insert_iter = insert_pair.first;
//                 if (insert_iter != mset.begin())
//                 {
//                     if (*insert_iter - *prev(insert_iter) <= t)
//                     {
//                         return true;
//                     }
//                 }
//                 if (insert_iter != prev(mset.end()))
//                 {
//                     if (*next(insert_iter) - *insert_iter <= t)
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         for (int i = k + 1; i < len; ++i)
//         {
//             mset.erase(nums[i - (k + 1)]);
//             auto insert_pair = mset.insert(nums[i]);
//             if (insert_pair.second == false)
//             {
//                 return true;
//             }
//             else
//             {
//                 auto insert_iter = insert_pair.first;
//                 if (insert_iter != mset.begin())
//                 {
//                     if (*insert_iter - *prev(insert_iter) <= t)
//                     {
//                         return true;
//                     }
//                 }
//                 if (insert_iter != prev(mset.end()))
//                 {
//                     if (*next(insert_iter) - *insert_iter <= t)
//                     {
//                         return true;
//                     }
//                 }
//             }
//         }
//         return false;
//     }
// };