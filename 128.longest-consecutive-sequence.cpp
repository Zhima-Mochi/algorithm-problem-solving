/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> uset;
        auto res = 0;
        for (auto &n : nums)
        {
            uset.insert(n);
        }
        for (auto &n : uset)
        {
            if (uset.count(n - 1) == 0)
            {
                auto count_num = n + 1;
                while (uset.count(count_num))
                {
                    ++count_num;
                }
                res = max(res, count_num - n);
            }
        }
        return res;
        // unordered_map<int, shared_ptr<pair<int, int>>> ump;
        // auto res = 0;
        // for (auto n : nums)
        // {
        //     if (ump.count(n) == 0)
        //     {
        //         if (ump.count(n - 1) && ump.count(n + 1))
        //         {
        //             ump[n] = ump[n - 1];
        //             (*ump[n]).second = (*ump[n + 1]).second;
        //             ump[(*ump[n + 1]).second] = ump[n];
        //         }
        //         else if (ump.count(n - 1))
        //         {
        //             ump[n] = ump[n - 1];
        //             (*ump[n]).second = n;
        //         }
        //         else if (ump.count(n + 1))
        //         {
        //             ump[n] = ump[n + 1];
        //             (*ump[n]).first = n;
        //         }
        //         else
        //         {
        //             ump[n] = shared_ptr<pair<int, int>>(new pair<int, int>(n, n));
        //         }
        //         res = max(res, (*ump[n]).second - (*ump[n]).first + 1);
        //     }
        // }
        // return res;
        // unordered_map<int, shared_ptr<shared_ptr<pair<int, int>>>> ump;
        // auto res = 0;
        // for (auto n : nums)
        // {
        //     if (ump.count(n) == 0)
        //     {
        //         if (ump.count(n - 1) && ump.count(n + 1))
        //         {
        //             ump[n] = ump[n - 1];
        //             (**ump[n]).second = (**ump[n + 1]).second;
        //             ump[(**ump[n + 1]).second]= ump[n];
        //         }
        //         else if (ump.count(n - 1))
        //         {
        //             ump[n] = ump[n - 1];
        //             (**ump[n]).second = n;
        //         }
        //         else if (ump.count(n + 1))
        //         {
        //             ump[n] = ump[n + 1];
        //             (**ump[n]).first = n;
        //         }
        //         else
        //         {
        //             ump[n] = shared_ptr<shared_ptr<pair<int, int>>>(new shared_ptr<pair<int, int>>(new pair<int, int>(n, n)));
        //         }
        //         res = max(res, (**ump[n]).second - (**ump[n]).first + 1);
        //     }
        // }
        // return res;
    }
};
// @lc code=end
//[-4,-1,4,-5,1,-6,9,-6,0,2,2,7,0,9,-3,8,9,-2,-6,5,0,3,4,-2]
