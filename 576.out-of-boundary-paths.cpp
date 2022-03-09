/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
#define MODULE 1000000007
class Solution
{
    int seen[50][50][51];
    int height;
    int width;

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        height = m;
        width = n;
        memset(seen, -1, sizeof(seen));
        return dfs(startRow, startColumn, maxMove);
    }
    int dfs(int row, int col, int maxMove)
    {
        if (maxMove == 0 || row < 0 || row >= height || col < 0 || col >= width)
        {
            return 0;
        }
        if (seen[row][col][maxMove] != -1)
        {
            return seen[row][col][maxMove];
        }
        int count = 0;
        if (row == 0)
        {
            ++count;
        }
        if (row == height - 1)
        {
            ++count;
        }
        if (col == 0)
        {
            ++count;
        }
        if (col == width - 1)
        {
            ++count;
        }
        seen[row][col][maxMove] = (count + (dfs(row - 1, col, maxMove - 1) + dfs(row + 1, col, maxMove - 1)) % MODULE + (dfs(row, col - 1, maxMove - 1) + dfs(row, col + 1, maxMove - 1)) % MODULE) % MODULE;
        return seen[row][col][maxMove];
    }
};
// @lc code=end
