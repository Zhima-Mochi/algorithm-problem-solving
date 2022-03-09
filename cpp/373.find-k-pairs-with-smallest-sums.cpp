/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */
#include <vector>
#include <array>
#include <climits>
#include <queue>
using namespace std;
// @lc code=start

class Solution
{
    using pr = pair<int, int>;

public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int len_1 = nums1.size(), len_2 = nums2.size();
        vector<vector<int>> res;
        auto Comp = [&nums1, &nums2](const array<int, 2> &l, const array<int, 2> &r)
        {
            if (nums1[l[0]] + nums2[l[1]] > nums1[r[0]] + nums2[r[1]])
            {
                return true;
            }
            else if (nums1[l[0]] + nums2[l[1]] == nums1[r[0]] + nums2[r[1]])
            {
                return nums1[l[0]] > nums1[r[0]];
            }
            else
            {
                return false;
            }
        };
        priority_queue<array<int, 2>,
                       vector<array<int, 2>>, decltype(Comp)>
            q(Comp);
        q.push({0, 0});
        while (k && !q.empty())
        {
            auto target = q.top();
            q.pop();
            res.push_back({nums1[target[0]], nums2[target[1]]});
            if (target[0] < len_1 - 1)
            {
                q.push({target[0] + 1, target[1]});
            }
            if (target[0] == 0 && target[1] < len_2 - 1)
            {
                q.push({target[0], target[1] + 1});
            }
            --k;
        }
        return res;
    }
};
// @lc code=end
