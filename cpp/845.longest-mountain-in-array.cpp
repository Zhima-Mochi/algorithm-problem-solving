/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */
#include <vector>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        // previous valley index
        int prev_valley_ind = -1;
        int w = arr.size();
        bool find_valley = true;
        int res = 0;
        for (int i = 1; i < w; ++i)
        {
            if (arr[i] == arr[i - 1])
            {
                if (find_valley && prev_valley_ind != -1 && i - prev_valley_ind > 2)
                {
                    res = max(res, i - prev_valley_ind);
                }
                prev_valley_ind = -1;
                find_valley = true;
                continue;
            }
            if (find_valley)
            {
                if (arr[i] > arr[i - 1])
                {
                    if (prev_valley_ind != -1)
                    {
                        res = max(res, i - prev_valley_ind);
                    }
                    prev_valley_ind = i - 1;
                    find_valley = false;
                }
            }
            else
            {
                if (arr[i] < arr[i - 1])
                {
                    find_valley = true;
                }
            }
        }
        if (find_valley && prev_valley_ind != -1 && w - prev_valley_ind > 2)
        {
            res = max(res, w - prev_valley_ind);
        }
        return res;
    }
};
// @lc code=end

// t:O(n), s:O(n)
// class Solution
// {
// public:
//     int longestMountain(vector<int> &arr)
//     {
//         int w = arr.size();
//         vector<int> l(w), r(w);
//         int res = 0;
//         for (int i = 1; i < w - 1; ++i)
//         {
//             if (arr[i] > arr[i - 1])
//             {
//                 l[i] = l[i - 1] + 1;
//             }
//             else
//             {
//                 l[i] = 0;
//             }
//         }
//         for (int i = w - 2; i > 0; --i)
//         {
//             if (arr[i + 1] < arr[i])
//             {
//                 r[i] = r[i + 1] + 1;
//             }
//             else
//             {
//                 r[i] = 0;
//             }
//         }
//         for (int i = 1; i < w - 1; ++i)
//         {
//             if (l[i] > 0 && r[i] > 0)
//             {
//                 res = max(res, l[i] + r[i] + 1);
//             }
//         }
//         return res;
//     }
// };