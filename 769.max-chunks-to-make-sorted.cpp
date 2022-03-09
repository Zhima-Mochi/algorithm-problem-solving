/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int res = 0;
        int max_val = 0, min_val = ~(1<<31);
        int lower_bnd = 0;
        for (int i = 0, width = arr.size(); i != width; ++i)
        {
            min_val = min(min_val, arr[i]);
            max_val = max(max_val, arr[i]);
            if (lower_bnd <= min_val && max_val <= i)
            {
                ++res;
                lower_bnd = max_val;
                min_val = ++max_val;
            }
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int maxChunksToSorted(vector<int> &arr)
//     {
//         vector<int> chunk_upper_bounds;
//         for (auto n : arr)
//         {
//             if (chunk_upper_bounds.empty() || n >= chunk_upper_bounds.back())
//             {
//                 chunk_upper_bounds.push_back(n);
//             }
//             else
//             {
//                 int s = chunk_upper_bounds.size();
//                 while (s > 1 && chunk_upper_bounds[s - 2] > n)
//                 {
//                     chunk_upper_bounds[s - 2] = chunk_upper_bounds[s - 1];
//                     chunk_upper_bounds.pop_back();
//                     --s;
//                 }
//             }
//         }
//         return chunk_upper_bounds.size();
//     }
// };