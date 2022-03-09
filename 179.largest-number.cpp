/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> vec;
        for (auto &n : nums)
        {
            vec.push_back(to_string(n));
        }
        sort(vec.begin(), vec.end(), [](const string &lhs, const string &rhs)
             {
                 auto cur_l = 0, cur_r = 0;
                 auto end_l = lhs.size(), end_r = rhs.size();
                 while (cur_l != end_l || cur_r != end_r)
                 {
                     if (cur_l == end_l)
                     {
                         cur_l = 0;
                     }
                     if (cur_r == end_r)
                     {
                         cur_r = 0;
                     }
                     if (lhs[cur_l] != rhs[cur_r])
                     {
                         return lhs[cur_l] > rhs[cur_r];
                     }
                     ++cur_l, ++cur_r;
                 }
                 return end_l > end_r;
             });
        if (vec[0] == "0")
        {
            return vec[0];
        }
        int len = vec.size();
        for (int i = 1; i != len; ++i)
        {
            vec[0].append(vec[i]);
        }
        return vec[0];
        // sort(nums.begin(), nums.end(), [](const int &lhn, const int &rhn)
        //      {
        //          const string lhs = to_string(lhn), rhs = to_string(rhn);
        //          auto cur_l = 0, cur_r = 0;
        //          auto end_l = lhs.size(), end_r = rhs.size();
        //          while (cur_l != end_l || cur_r != end_r)
        //          {
        //              if (cur_l == end_l)
        //              {
        //                  cur_l = 0;
        //              }
        //              if (cur_r == end_r)
        //              {
        //                  cur_r = 0;
        //              }
        //              if (lhs[cur_l] != rhs[cur_r])
        //              {
        //                  return lhs[cur_l] > rhs[cur_r];
        //              }
        //              ++cur_l, ++cur_r;
        //          }
        //          return end_l > end_r;
        //      });
        // if (nums[0] == 0)
        // {
        //     return "0";
        // }
        // string res;
        // for (auto &n : nums)
        // {
        //     res.append(to_string(n));
        // }
        // return res;
    }
};
// @lc code=end
