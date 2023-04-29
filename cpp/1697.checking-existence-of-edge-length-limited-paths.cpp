/*
 * @lc app=leetcode id=1697 lang=cpp
 *
 * [1697] Checking Existence of Edge Length Limited Paths
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
    int findGroup(vector<int> &records, int x)
    {
        if (records[x] == x)
        {
            return x;
        }
        return records[x] = findGroup(records, records[x]);
    }

    void merge(vector<int> &records, int x, int y)
    {
        x = findGroup(records, x);
        y = findGroup(records, y);
        records[y] = x;
    }

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {

        sort(edgeList.begin(), edgeList.end(), [](vector<int> &e1, vector<int> &e2)
             { return e1[2] < e2[2]; });

        vector<int> index(queries.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int i, int j)
             { return queries[i][2] < queries[j][2]; });

        vector<int> records(n);
        iota(records.begin(), records.end(), 0);
        vector<bool> res(queries.size());
        int k = 0;
        for (auto i : index)
        {
            while (k < edgeList.size() && edgeList[k][2] < queries[i][2])
            {
                merge(records, edgeList[k][0], edgeList[k][1]);
                k++;
            }
            res[i] = findGroup(records, queries[i][0]) == findGroup(records, queries[i][1]);
        }
        return res;
    }
};
// @lc code=end
