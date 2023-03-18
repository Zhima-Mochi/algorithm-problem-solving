/*
 * @lc app=leetcode id=2359 lang=cpp
 *
 * [2359] Find Closest Node to Given Two Nodes
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int w = edges.size();
        vector<int> from1(w, -1), from2(w, -1);
        int distance = 0, pos = node1;
        while (pos != -1 && from1[pos] == -1)
        {
            from1[pos] = distance;
            distance++;
            pos = edges[pos];
        }
        distance = 0;
        pos = node2;
        while (pos != -1 && from2[pos] == -1)
        {
            from2[pos] = distance;
            distance++;
            pos = edges[pos];
        }
        int max_val = 0;
        int res = -1;
        for (int i = 0; i != w; ++i)
        {
            if (from1[i] != -1 && from2[i] != -1)
            {
                if (res == -1)
                {
                    res = i;
                    max_val = max(from1[i], from2[i]);
                }
                else
                {
                    int m = max(from1[i], from2[i]);
                    if (m < max_val)
                    {
                        max_val = m;
                        res = i;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
