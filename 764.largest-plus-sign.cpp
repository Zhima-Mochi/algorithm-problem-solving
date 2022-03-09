/*
 * @lc app=leetcode id=764 lang=cpp
 *
 * [764] Largest Plus Sign
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<int>> bfs(n, vector<int>(n));
        for (int i = 0; i != n; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                bfs[i][j] = 1 + min({i, n - i - 1, j, n - j - 1});
            }
        }
        for (auto &pair : mines)
        {
            bfs[pair[0]][pair[1]] = 0;
        }

        for (auto &pair : mines)
        {
            helpler(bfs, n, pair[0], pair[1]);
        }

        int res = 0;
        for (auto &row_elem : bfs)
        {
            for (auto &val : row_elem)
            {
                res = max(res, val);
            }
        }
        return res;
    }
    void helpler(vector<vector<int>> &bfs, int n, int i, int j)
    {

        for (int up = 1; up != i + 1; ++up)
        {
            if (bfs[i - up][j] == 0)
            {
                break;
            }
            bfs[i - up][j] = min(up, bfs[i - up][j]);
        }
        for (int left = 1; left != j + 1; ++left)
        {
            if (bfs[i][j - left] == 0)
            {
                break;
            }
            bfs[i][j - left] = min(left, bfs[i][j - left]);
        }
        for (int down = 1; down != n - i; ++down)
        {
            if (bfs[i + down][j] == 0)
            {
                break;
            }
            bfs[i + down][j] = min(down, bfs[i + down][j]);
        }
        for (int right = 1; right != n - j; ++right)
        {
            if (bfs[i][j + right] == 0)
            {
                break;
            }
            bfs[i][j + right] = min(right, bfs[i][j + right]);
        }
    }
};
// @lc code=end
