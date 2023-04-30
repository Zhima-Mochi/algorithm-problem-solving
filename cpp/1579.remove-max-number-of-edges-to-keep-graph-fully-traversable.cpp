/*
 * @lc app=leetcode id=1579 lang=cpp
 *
 * [1579] Remove Max Number of Edges to Keep Graph Fully Traversable
 */
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(n*m) s:O(n)
class Solution
{
    int getRoot(vector<int> &points, int i)
    {
        if (points[i] == i)
            return i;
        return points[i] = getRoot(points, points[i]);
    }
    bool unionRoot(vector<int> &points, int i, int j)
    {
        int root_i = getRoot(points, i);
        int root_j = getRoot(points, j);
        if (root_i == root_j)
        {
            return false;
        }
        points[root_i] = root_j;
        return true;
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        vector<int> pointsA(n + 1);
        vector<int> pointsB(n + 1);
        iota(pointsA.begin(), pointsA.end(), 0);
        iota(pointsB.begin(), pointsB.end(), 0);
        vector<vector<int>> typeA = {};
        vector<vector<int>> typeB = {};

        int res = 0;
        for (auto &edge : edges)
        {
            if (edge[0] == 3)
            {
                if (!unionRoot(pointsA, edge[1], edge[2]))
                {
                    res++;
                }
                unionRoot(pointsB, edge[1], edge[2]);
            }
            else if (edge[0] == 1)
            {
                typeA.push_back(edge);
            }
            else if (edge[0] == 2)
            {
                typeB.push_back(edge);
            }
        }

        for (auto &edge : edges)
        {

            if (edge[0] == 1)
            {
                if (!unionRoot(pointsA, edge[1], edge[2]))
                {
                    res++;
                }
            }
            else if (edge[0] == 2)
            {
                if (!unionRoot(pointsB, edge[1], edge[2]))
                {
                    res++;
                }
            }
        }

        for (int i = 1; i != n + 1; ++i)
        {
            if (unionRoot(pointsA, i, 1))
            {
                return -1;
            }
            if (unionRoot(pointsB, i, 1))
            {
                return -1;
            }
        }
        return res;
    }
};
// @lc code=end
