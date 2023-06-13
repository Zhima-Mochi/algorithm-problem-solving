/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(nlogn) s:O(nlogn)
class TreeAncestor
{
    int _n;
    vector<vector<int>> records;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        _n = n;
        records.resize(n, vector<int>(20, -1));
        for (int i = 0; i < n; ++i)
        {
            records[i][0] = parent[i];
        }
        for (int j = 1; j < 20; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                if (records[i][j - 1] != -1)
                {
                    records[i][j] = records[records[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int j = 19; j >= 0; --j)
        {
            if (k >= (1 << j))
            {
                node = records[node][j];
                if (node == -1)
                {
                    return -1;
                }
                k -= (1 << j);
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end
