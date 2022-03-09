/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        int population[101] = {};
        int res;
        int max_popu = 0;
        for (auto &log : logs)
        {
            population[log[0] - 1950] += 1;
            population[log[1] - 1950] -= 1;
        }
        int cur_popu = 0;
        for (int i = 0; i != 101; ++i)
        {
            cur_popu += population[i];
            if (cur_popu > max_popu)
            {
                max_popu=cur_popu;
                res = 1950 + i;
            }
        }
        return res;
    }
};
// @lc code=end

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        sort(logs.begin(), logs.end(), [](vector<int> &l, vector<int> &r)
             { return l[0] < r[0]; });
        priority_queue<int, vector<int>, greater<int>>
            death_year;
        int population = 0;
        int res;
        for (auto log : logs)
        {
            while (!death_year.empty() && death_year.top() <= log[0])
            {
                death_year.pop();
            }
            death_year.push(log[1]);
            if (death_year.size() > population)
            {
                population = death_year.size();
                res = log[0];
            }
        }
        return res;
    }
};