// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem282.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<string, unordered_map<long, vector<string>>> umap;
    unordered_map<string, unordered_map<string, long>> multiply_umap;
public:
    vector<string> addOperators(string num, int target)
    {
        int len = num.size();
        vector<string> res;
        for (int i = 0; i != len - 1; ++i)
        {
            string left_string = num.substr(0, i + 1);
            string right_string = num.substr(i + 1);
            helpler2(left_string);
            auto &left_candidates = multiply_umap[left_string];
            for (auto &m : left_candidates)
            {
                helpler1(right_string, target - m.second);
                auto &right_candidates = umap[right_string][target - m.second];
                for (auto &n : right_candidates)
                {
                    res.push_back(m.first + n);
                }
            }
        }
        helpler2(num);
        for (auto &p : multiply_umap[num])
        {
            if (p.second == target)
            {
                res.push_back(p.first);
            }
        }
        return res;
    }
    void helpler1(string &num, int target)
    {
        int len = num.size();
        if (umap[num].count(target))
        {
            return;
        }
        else
        {
            for (int i = 0; i != len - 1; ++i)
            {
                string left_string = num.substr(0, i + 1);
                string right_string = num.substr(i + 1);
                helpler2(left_string);
                auto &left_candidates = multiply_umap[left_string];
                for (auto &m : left_candidates)
                {
                    helpler1(right_string, target - m.second);
                    for (auto &n : umap[right_string][target - m.second])
                    {
                        umap[num][target].push_back('+' + m.first + n);
                    }
                    helpler1(right_string, target + m.second);
                    for (auto &n : umap[right_string][target + m.second])
                    {
                        umap[num][target].push_back('-' + m.first + n);
                    }
                }
            }
            helpler2(num);
            for (auto &p : multiply_umap[num])
            {
                if (p.second == target)
                {
                    umap[num][target].push_back('+' + p.first);
                }
                if (-p.second == target)
                {
                    umap[num][target].push_back('-' + p.first);
                }
            }
        }
    }
    void helpler2(string &num)
    {
        int len = num.size();
        if (multiply_umap.count(num))
        {
            return;
        }
        else
        {
            for (int i = 0; i != len - 1; ++i)
            {
                if (num[0] == '0' && i > 0)
                {
                    continue;
                }
                string left_string = num.substr(0, i + 1);
                string right_string = num.substr(i + 1);
                long left_num = stol(num.substr(0, i + 1));
                helpler2(right_string);
                auto &right_candidates = multiply_umap[right_string];
                for (auto &n : right_candidates)
                {
                    multiply_umap[num][left_string + '*' + n.first] = left_num * n.second;
                }
            }
            if (num[0] != '0' || len == 1)
            {
                multiply_umap[num][num] = stol(num);
            }
        }
    }
};
// @lc code=end