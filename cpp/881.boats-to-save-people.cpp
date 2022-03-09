/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
// t:O(n*log(n)), s:O(1)
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int w = people.size();
        sort(people.begin(), people.end());
        int left = 0;
        int right = w - 1;
        int res = 0;
        while (left <= right)
        {
            ++res;
            if (left == right)
            {
                ++left;
            }
            else if (people[right] + people[left] <= limit)
            {
                --right;
                ++left;
            }
            else
            {
                --right;
            }
        }
        return res;
    }
};
// @lc code=end
