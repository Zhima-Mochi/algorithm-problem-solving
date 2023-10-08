/*
 * @lc app=leetcode id=2059 lang=cpp
 *
 * [2059] Minimum Operations to Convert Number
 */
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// @lc code=start
// t:O(n), s:O(1)
class Solution
{
public:
    int minimumOperations(vector<int> &nums, int start, int goal)
    {
        queue<int> q;
        unordered_set<int> visited;
        visited.insert(start);
        q.push(start);
        int turn = 0;
        while (!q.empty())
        {
            int q_len = q.size();
            while (q_len--)
            {
                int curr = q.front();
                q.pop();
                if (curr == goal)
                {
                    return turn;
                }
                for (auto num : nums)
                {
                    if (curr + num == goal || curr - num == goal || (curr ^ num) == goal)
                    {
                        return turn + 1;
                    }
                    if (curr + num <= 1000 && curr + num >= 0 && visited.find(curr + num) == visited.end())
                    {
                        q.push(curr + num);
                        visited.insert(curr + num);
                    }
                    if (curr - num <= 1000 && curr - num >= 0 && visited.find(curr - num) == visited.end())
                    {
                        q.push(curr - num);
                        visited.insert(curr - num);
                    }
                    if ((curr ^ num) <= 1000 && (curr ^ num) >= 0 && visited.find((curr ^ num)) == visited.end())
                    {
                        q.push((curr ^ num));
                        visited.insert((curr ^ num));
                    }
                }
            }
            turn++;
        }
        return -1;
    }
};
// @lc code=end
