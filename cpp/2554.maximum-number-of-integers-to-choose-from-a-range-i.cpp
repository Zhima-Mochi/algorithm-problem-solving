/*
 * @lc app=leetcode id=2554 lang=cpp
 *
 * [2554] Maximum Number of Integers to Choose From a Range I
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxCount(vector<int> &banned, int n, int maxSum)
    {
        unordered_set<int> banSet;
        for (auto b : banned)
        {
            banSet.insert(b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (banSet.count(i))
            {
                continue;
            }
            if (maxSum < i)
            {
                break;
            }
            ans += 1;
            maxSum -= i;
        }
        return ans;
    }
};
// @lc code=end
