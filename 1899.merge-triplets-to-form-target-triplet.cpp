/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<int> records = {0, 0, 0};
        for (auto &triplet : triplets)
        {
            bool flag = true;
            for (int i = 0; i != 3; ++i)
            {
                if (triplet[i] > target[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                for (int i = 0; i != 3; ++i)
                {
                    records[i] = max(records[i], triplet[i]);
                }
            }
        }
        return records == target;
    }
};
// @lc code=end
