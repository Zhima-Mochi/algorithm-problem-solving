/*
 * @lc app=leetcode id=1705 lang=cpp
 *
 * [1705] Maximum Number of Eaten Apples
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        auto comp = [](pair<int, int> &l, pair<int, int> &r)
        {
            return l.first > r.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        int width = apples.size();
        int ind = 0;
        int res = 0;
        for (ind = 0; ind != width; ++ind)
        {
            pq.push({days[ind] + ind - 1, apples[ind]});

            while (!pq.empty() && (pq.top().first < ind || pq.top().second <= 0))
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                auto elem = pq.top();
                pq.pop();
                ++res;
                pq.push({elem.first, elem.second - 1});
            }
        }
        while (!pq.empty())
        {
            while (!pq.empty() && (pq.top().first < ind || pq.top().second <= 0))
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                auto elem = pq.top();
                pq.pop();
                int add = min(elem.first - ind + 1, elem.second);
                res += add;
                ind += add;
            }
        }
        return res;
    }
};
// @lc code=end
