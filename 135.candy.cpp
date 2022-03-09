/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(n), s:O(n)
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int w = ratings.size();
        vector<int> get_candy(w, 1);
        for (int i = 1; i != w; ++i)
        {
            if (ratings[i] > ratings[i - 1])
            {
                get_candy[i] = max(get_candy[i], get_candy[i - 1] + 1);
            }
        }
        int res = get_candy[w - 1];
        for (int i = w - 2; i != -1; -- i)
        {
            if (ratings[i] > ratings[i + 1])
            {
                get_candy[i] = max(get_candy[i], get_candy[i + 1] + 1);
            }
            res += get_candy[i];
        }
        return res;
    }
};
// @lc code=end
// t:O(nlog(n)), s:O(n)
// class Solution
// {
// public:
//     int candy(vector<int> &ratings)
//     {
//         int w = ratings.size();
//         vector<int> idx_sorted_by_rate(w);
//         iota(idx_sorted_by_rate.begin(), idx_sorted_by_rate.end(), 0);
//         sort(idx_sorted_by_rate.begin(), idx_sorted_by_rate.end(), [&](int l, int r)
//              { return ratings[l] < ratings[r]; });
//         vector<int> get_candy(w, 1);
//         int res = 0;
//         for (auto idx : idx_sorted_by_rate)
//         {
//             if (idx > 0 && ratings[idx] > ratings[idx - 1])
//             {
//                 get_candy[idx] = max(get_candy[idx - 1] + 1, get_candy[idx]);
//             }
//             if (idx < w - 1 && ratings[idx] > ratings[idx + 1])
//             {
//                 get_candy[idx] = max(get_candy[idx + 1] + 1, get_candy[idx]);
//             }
//             res += get_candy[idx];
//         }
//         return res;
//     }
// };
