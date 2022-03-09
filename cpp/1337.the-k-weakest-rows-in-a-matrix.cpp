/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<vector<int>, int>> q;
        int len = mat.size();
        for (int i = 0; i != len; ++i)
        {
            q.push({mat[i], i});
            if (q.size() > k)
            {
                q.pop();
            }
        }
        vector<int> res(k);
        while (!q.empty())
        {
            res[--k]=q.top().second;
            q.pop();
        }
        return res;
    }
};
// @lc code=end
