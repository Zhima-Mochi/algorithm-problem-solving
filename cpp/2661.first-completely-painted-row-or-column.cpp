/*
 * @lc app=leetcode id=2661 lang=cpp
 *
 * [2661] First Completely Painted Row or Column
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(m*n), s:O(m*n)
class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> r_rec(m), c_rec(n);
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i != m; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                mp[mat[i][j]] = {i, j};
            }
        }
        int l = arr.size();
        for (int i = 0; i != l; ++i)
        {
            auto p = mp[arr[i]];
            if (++r_rec[p.first] == n || ++c_rec[p.second] == m)
            {
                return i;
            }
        }
        return m * n;
    }
};
// @lc code=end
