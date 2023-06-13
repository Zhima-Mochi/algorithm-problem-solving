/*
 * @lc app=leetcode id=1240 lang=cpp
 *
 * [1240] Tiling a Rectangle with the Fewest Squares
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int res;
    vector<vector<bool>> square;
    int _n, _m;
    int tilingRectangle(int n, int m)
    {
        square = vector<vector<bool>>(n, vector<bool>(m, false));
        _n = n;
        _m = m;
        res = _n * _m;
        dfs(0, 0, 0);
        return res;
    }

    void dfs(int x, int y, int count)
    {
        if (count >= res)
        {
            return;
        }
        if (y >= _m)
        {
            dfs(x + 1, 0, count);
            return;
        }
        if (x >= _n)
        {
            res = count;
            return;
        }

        if (square[x][y])
        {
            dfs(x, y + 1, count);
            return;
        }

        for (int r = min(_n - x, _m - y); r > 0; r--)
        {
            if (has_capacity(x, y, r))
            {
                fill(x, y, r);
                dfs(x, y + r, count + 1);
                clear(x, y, r);
            }
        }
    }

    bool has_capacity(int x, int y, int r)
    {
        for (int i = x; i < x + r; i++)
        {
            for (int j = y; j < y + r; j++)
            {
                if (square[i][j] != false)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void fill(int x, int y, int r)
    {
        for (int i = x; i < x + r; i++)
        {
            for (int j = y; j < y + r; j++)
            {
                square[i][j] = true;
            }
        }
    }

    void clear(int x, int y, int r)
    {
        for (int i = x; i < x + r; i++)
        {
            for (int j = y; j < y + r; j++)
            {
                square[i][j] = false;
            }
        }
    }
};
// @lc code=end
