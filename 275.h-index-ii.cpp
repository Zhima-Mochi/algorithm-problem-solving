/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int len = citations.size();
        int left = 0, right = len - 1;
        while (left <= right)
        {
            auto mid = left + (right - left) / 2;
            if (citations[mid] < len - mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return len - left;
    }
};
// @lc code=end
