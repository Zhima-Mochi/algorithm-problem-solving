/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res = {};
        vector<int> vec;
        for (int i = 1; i != k + 1; ++i)
        {
            vec.push_back(i);
        }
        res.push_back(vec);
        int i = k - 1;
        while (i >= 0)
        {
            if (++vec[i] > n)
            {
                --i;
            }
            else if (i == k - 1)
            {
                res.push_back(vec);
            }
            else
            {
                ++i;
                vec[i] = vec[i - 1];
            }
        }
        return res;
        // vector<vector<int>> res = {};
        // for (int i = 1; i <= n - k + 1; i++)
        // {
        //     res.push_back(vector<int>{i});
        // }
        // --k;
        // while (k)
        // {
        //     vector<vector<int>> new_vec;
        //     for (auto &v : res)
        //     {
        //         auto start = v.back() + 1;
        //         for (int i = start; i <= n - k + 1; i++)
        //         {
        //             new_vec.push_back(v);
        //             new_vec.back().push_back(i);
        //         }
        //     }
        //     res = new_vec;
        //     --k;
        // }
        // return res;
    }
};
// @lc code=end
