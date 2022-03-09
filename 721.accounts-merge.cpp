// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem721.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
    int find(vector<int> &root_index, int index)
    {
        while (root_index[index] != index)
        {
            index = root_index[index];
        }
        return index;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int width = accounts.size();
        unordered_map<string, int> email2id;
        vector<int> root_index(width);
        unordered_map<int, vector<string>> id2email;
        int ind = 0;
        for (auto &account : accounts)
        {
            root_index[ind] = ind;
            // root_index[ind] = ind++; undefined behavior C??
            ++ind;
            for (int i = 1, a_width = account.size(); i != a_width; ++i)
            {
                if (email2id.count(account[i]))
                {
                    int current_root_index = find(root_index, ind - 1);
                    int new_root_index = find(root_index, email2id[account[i]]);
                    root_index[current_root_index] = new_root_index;
                    root_index[ind - 1] = new_root_index;
                }
                else
                {
                    // cuurent root index is close to true root index
                    email2id[account[i]] = root_index[ind - 1];
                }
            }
        }
        for (auto &p : email2id)
        {
            id2email[find(root_index, p.second)].push_back(p.first);
        }
        vector<vector<string>> res;
        for (auto &p : id2email)
        {
            res.push_back(vector<string>{accounts[p.first][0]});
            res.back().insert(res.back().end(), p.second.begin(), p.second.end());
            sort(res.back().begin() + 1, res.back().end());
        }
        return res;
    }
};
// @lc code=end

// class Solution
// {
//     unordered_map<string, unordered_set<string>> graph;
//     unordered_map<string, string> email2name;
//     vector<vector<string>> res;
//     unordered_set<string> visited;

// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
//     {
//         for (auto &account : accounts)
//         {
//             auto name = account[0];
//             graph[account[1]];
//             for (int i = 1, width = account.size(); i != width; ++i)
//             {
//                 email2name[account[i]] = name;
//                 if (i != 1)
//                 {
//                     graph[account[i]].insert(account[i - 1]);
//                     graph[account[i - 1]].insert(account[i]);
//                 }
//             }
//         }

//         for (auto &p : graph)
//         {
//             auto &email = p.first;
//             if (!visited.count(email))
//             {
//                 visited.insert(email);
//                 res.push_back(vector<string>{email2name[email]});
//                 dfs(res.back(), email);
//                 sort(res.back().begin() + 1, res.back().end());
//             }
//         }
//         return res;
//     }
//     void dfs(vector<string> &emails, string email)
//     {
//         emails.push_back(email);
//         unordered_set<string> neighbors = graph[email];
//         for (auto neighbor : neighbors)
//         {
//             if (!visited.count(neighbor))
//             {
//                 visited.insert(neighbor);
//                 dfs(emails, neighbor);
//             }
//         }
//     }
// };