/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_multiset<int> uset;
        vector<int> res;
        for (auto &n : nums1)
        {
            uset.insert(n);
        }
        for (auto &n : nums2)
        {
            if (uset.count(n))
            {
                uset.erase(uset.find(n));
                res.push_back(n);
            }
        }
        return res;
    }
};
// @lc code=end
