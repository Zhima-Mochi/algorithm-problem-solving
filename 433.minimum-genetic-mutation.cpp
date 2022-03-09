/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        sort(bank.begin(), bank.end());
        bank.erase(unique(bank.begin(), bank.end()), bank.end());
        queue<string> q;
        q.push(start);
        int round = 0;
        unordered_set<string> used_gen;
        used_gen.insert(start);
        while (!q.empty())
        {
            ++round;
            auto q_len=q.size();
            while (q_len--)
            {
                auto cur_gene = q.front();
                q.pop();
                for (auto &s : bank)
                {
                    if (canMutate(cur_gene, s))
                    {
                        if (s == end)
                        {
                            return round;
                        }
                        else if (!used_gen.count(s))
                        {
                            used_gen.insert(s);
                            q.push(s);
                        }
                    }
                }
            }
        }
        return -1;
    }
    bool canMutate(string &og, string &mut)
    {
        short count = 0;
        for (int i = 0; i != 8; ++i)
        {
            if (og[i] != mut[i])
            {
                ++count;
            }
        }
        return count == 1;
    }
};
// @lc code=end
