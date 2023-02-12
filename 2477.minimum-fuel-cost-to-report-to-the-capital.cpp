/*
 * @lc app=leetcode id=2477 lang=cpp
 *
 * [2477] Minimum Fuel Cost to Report to the Capital
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <functional>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        unordered_map<int, vector<int>> neighbor;
        for (auto &road : roads)
        {
            neighbor[road[0]].push_back(road[1]);
            neighbor[road[1]].push_back(road[0]);
        }
        unordered_set<int> hasSeen;
        hasSeen.insert(0);
        long long res = 0;
        function<int(int, int)> helper = [&](int city, int distance)
        {
            int r = 1;
            for (auto n : neighbor[city])
            {
                if (!hasSeen.count(n))
                {
                    hasSeen.insert(n);
                    auto cnt = helper(n, distance + 1);
                    if (cnt > 0)
                    {
                        res += 1;
                        r += cnt;
                    }
                }
            }
            while (r >= seats)
            {
                res += distance;
                r -= seats;
            }
            return r;
        };
        helper(0, 0);
        return res;
    }
};
// @lc code=end
