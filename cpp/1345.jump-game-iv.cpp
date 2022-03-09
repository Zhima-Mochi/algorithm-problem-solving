/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<int, vector<int>> idx_record;

public:
    int minJumps(vector<int> &arr)
    {
        int w = arr.size();
        if (w == 1)
        {
            return 0;
        }
        for (int i = 0; i != w; ++i)
        {
            idx_record[arr[i]].push_back(i);
        }
        vector<bool> visited(w);
        queue<int> q;
        q.push(w - 1);
        visited[w - 1] = true;
        int turn = 0;
        while (!q.empty())
        {
            ++turn;
            int q_w = q.size();
            while (q_w--)
            {
                int pos = q.front();
                q.pop();
                if (idx_record.count(arr[pos]))
                {
                    for (auto n : idx_record[arr[pos]])
                    {
                        if (!visited[n])
                        {
                            if (n == 0)
                            {
                                return turn;
                            }
                            visited[n] = true;
                            q.push(n);
                        }
                    }
                    idx_record.erase(arr[pos]);
                }
                if (pos < w - 2 && !visited[pos + 1])
                {
                    visited[pos + 1] = true;
                    q.push(pos + 1);
                }
                if (pos > 0 && !visited[pos - 1])
                {
                    if (pos - 1 == 0)
                    {
                        return turn;
                    }
                    visited[pos - 1] = true;
                    q.push(pos - 1);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
