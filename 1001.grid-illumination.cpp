/*
 * @lc app=leetcode id=1001 lang=cpp
 *
 * [1001] Grid Illumination
 */
#include <vector>
#include <unordered_set>
#include<unordered_map>
using namespace std;
// @lc code=start
// t:O(len(lamps)+len(queries)), s:O(len(lamps))
class Solution
{
    unordered_map<int,int> row_light, col_light, slash_light, backslash_light;
    int w;
    unordered_set<long long> light_lamp_pos;

public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        w = n;
        for (auto &lamp : lamps)
        {
            turn_on(lamp[0], lamp[1]);
        }
        vector<int> res;
        for (auto &q : queries)
        {
            res.push_back(is_turn_on(q[0], q[1]));
            if (res.back())
            {
                for (int i = q[0] - 1; i != q[0] + 2; ++i)
                {
                    for (int j = q[1] - 1; j != q[1] + 2; ++j)
                    {
                        turn_off(i, j);
                    }
                }
            }
        }
        return res;
    }
    bool is_turn_on(int row, int col)
    {
        return row_light[row] || col_light[col] || backslash_light[w - 1 - row + col] || slash_light[row + col];
    }
    void turn_on(int row, int col)
    {
        long long pos = (static_cast<long long>(row) << 32) + col;
        if (!light_lamp_pos.count(pos))
        {
            light_lamp_pos.insert(pos);
            ++row_light[row];
            ++col_light[col];
            ++backslash_light[w - 1 - row + col];
            ++slash_light[row + col];
        }
    }
    void turn_off(int row, int col)
    {
        if (row >= 0 && col >= 0 && row < w && col < w)
        {
            long long pos = (static_cast<long long>(row) << 32) + col;
            if (light_lamp_pos.count(pos))
            {
                --row_light[row];
                --col_light[col];
                --backslash_light[w - 1 - row + col];
                --slash_light[row + col];
                light_lamp_pos.erase(pos);
            }
        }
    }
};
// @lc code=end
