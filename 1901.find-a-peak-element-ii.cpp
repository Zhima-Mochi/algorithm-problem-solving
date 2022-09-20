/*
 * @lc app=leetcode id=1901 lang=cpp
 *
 * [1901] Find a Peak Element II
 */
#include <vector>
using namespace std;
// @lc code=start
// t: O(nlog(m)) s:O(1)
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int h = mat.size();
        int w = mat[0].size();
        int left = 0;
        int right = h - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int col = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (mat[mid][col] < mat[mid + 1][col])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return {left, static_cast<int>(max_element(mat[left].begin(), mat[left].end()) - mat[left].begin())};
    }
};
// @lc code=end
