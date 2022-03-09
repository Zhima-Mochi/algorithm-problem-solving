/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        unordered_map<string, vector<int>> umap;
        int len = expression.size();
        vector<int> res;
        for (int i = 0; i != len; ++i)
        {
            if (!isdigit(expression[i]))
            {
                auto left = helpler(expression.substr(0, i), umap);
                auto right = helpler(expression.substr(i + 1), umap);
                for (auto &lval : left)
                {
                    for (auto &rval : right)
                    {
                        switch (expression[i])
                        {
                        case '+':
                            res.push_back(lval + rval);
                            break;
                        case '-':
                            res.push_back(lval - rval);
                            break;
                        case '*':
                            res.push_back(lval * rval);
                            break;
                        }
                    }
                }
            }
        }
        if (res.empty())
        {
            res.push_back(stoi(expression));
        }
        return res;
    }
    vector<int> helpler(string s, unordered_map<string, vector<int>> &umap)
    {
        if (umap.count(s))
        {
            return umap[s];
        }
        else
        {
            int len = s.size();
            vector<int> collection;
            for (int i = 0; i != len; ++i)
            {
                if (!isdigit(s[i]))
                {
                    auto left = helpler(s.substr(0, i), umap);
                    auto right = helpler(s.substr(i + 1), umap);
                    for (auto &lval : left)
                    {
                        for (auto &rval : right)
                        {
                            switch (s[i])
                            {
                            case '+':
                                collection.push_back(lval + rval);
                                break;
                            case '-':
                                collection.push_back(lval - rval);
                                break;
                            case '*':
                                collection.push_back(lval * rval);
                                break;
                            }
                        }
                    }
                }
            }
            if (collection.empty())
            {
                collection.push_back(stoi(s));
            }
            umap[s] = collection;
            return collection;
        }
    }
};
// @lc code=end
