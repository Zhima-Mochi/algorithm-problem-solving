/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        auto arr2 = arr;
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        for (auto &n : arr)
        {
            n = lower_bound(arr2.begin(), arr2.end(), n) - arr2.begin() + 1;
        }
        return arr;
    }
};
// @lc code=end
// class Solution
// {
// public:
//     vector<int> arrayRankTransform(vector<int> &arr)
//     {
//         map<int, vector<int>> pos_map;
//         int len = arr.size();
//         for (int i = 0; i != len; ++i)
//         {
//             pos_map[arr[i]].push_back(i);
//         }
//         vector<int> res(len);
//         int rank = 1;
//         for (auto &pos_vec : pos_map)
//         {
//             for (auto pos : pos_vec.second)
//             {
//                 res[pos] = rank;
//             }
//             ++rank;
//         }
//         return res;
//     }
// };

// class Solution
// {
// public:
//     vector<int> arrayRankTransform(vector<int> &arr)
//     {
//         map<int, int> rank_map;
//         int len = arr.size();
//         for (int i = 0; i != len; ++i)
//         {
//             rank_map[arr[i]];
//         }
//         int rank = 1;
//         for (auto &rank_pair : rank_map)
//         {
//             rank_pair.second = rank;
//             ++rank;
//         }
//         for (auto &n : arr)
//         {
//             n = rank_map[n];
//         }
//         return arr;
//     }
// };