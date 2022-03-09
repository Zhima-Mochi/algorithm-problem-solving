/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// T:O(N log(N)), S:O(1)
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int res = 0;
        int width = nums.size();
        sort(nums.begin(), nums.end());
        if (k > 0)
        {
            nums.erase(unique(nums.begin(), nums.end()), nums.end());
            int left = 0, right = 0;
            while (right != width)
            {
                if (nums[right] - nums[left] < k)
                {
                    ++right;
                }
                else if (nums[right] - nums[left] == k)
                {
                    ++res;
                    ++left;
                    ++right;
                }
                else
                {
                    ++left;
                }
            }
        }
        else
        {
            int pos = 1;
            while (pos != width)
            {
                if (nums[pos] == nums[pos - 1])
                {
                    ++res;
                    ++pos;
                    while (pos != width && nums[pos] == nums[pos - 1])
                    {
                        ++pos;
                    }
                }
                else
                {
                    ++pos;
                }
            }
        }

        return res;
    }
};
// @lc code=end

// T:O(N), S:O(N)
// class Solution
// {
// public:
//     int findPairs(vector<int> &nums, int k)
//     {
//         int res = 0;
//         if (k > 0)
//         {
//             unordered_set<int> appear;
//             for (auto n : nums)
//             {
//                 appear.insert(n);
//             }
//             for (auto n : nums)
//             {
//                 if (appear.count(n))
//                 {
//                     appear.erase(n);
//                     if (appear.empty())
//                     {
//                         break;
//                     }
//                 }
//                 else
//                 {
//                     continue;
//                 }
//                 if (appear.count(n + k))
//                 {
//                     ++res;
//                 }
//                 if (appear.count(n - k))
//                 {
//                     ++res;
//                 }
//             }
//         }
//         else
//         {
//             unordered_map<int, int> count;
//             for (auto n : nums)
//             {
//                 ++count[n];
//                 if (count[n] == 2)
//                 {
//                     ++res;
//                 }
//             }
//         }

//         return res;
//     }
// };
// T:O(N**2), S:O(N)
// class Solution
// {
// public:
//     int findPairs(vector<int> &nums, int k)
//     {
//         unordered_map<int, unordered_set<int>> seen;
//         int res = 0;
//         int width = nums.size();
//         for (int i = 0; i != width - 1; ++i)
//         {
//             if (seen.count(nums[i]))
//             {
//                 continue;
//             }
//             else
//             {
//                 seen[nums[i]];
//             }
//             for (int j = i + 1; j != width; ++j)
//             {
//                 if (abs(nums[i] - nums[j]) == k)
//                 {
//                     if (seen[nums[i]].count(nums[j]))
//                     {
//                         continue;
//                     }
//                     else if (seen.count(nums[j]) && seen[nums[j]].count(nums[i]))
//                     {
//                         continue;
//                     }
//                     else
//                     {
//                         ++res;
//                         seen[nums[i]].insert(nums[j]);
//                     }
//                 }
//             }
//         }
//         return res;
//     }
// };