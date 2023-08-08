/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
// t:O(n^2), s:O(n)
class Solution
{
public:
    string countOfAtoms(string formula)
    {
        unordered_map<string, int> cur;
        vector<unordered_map<string, int>> records;
        int w = formula.size();
        string atom = "";
        int count = 0;
        bool check = false;
        for (int i = 0; i != w; ++i)
        {
            if (isdigit(formula[i]))
            {
                count *= 10;
                count += formula[i] - '0';
                continue;
            }
            else if (islower(formula[i]))
            {
                atom += formula[i];
                continue;
            }
            if (check)
            {
                count = max(count, 1);
                for (auto &[atom, num] : cur)
                {
                    records.back()[atom] += num * count;
                }
                check = false;
                count = 0;
                cur = records.back();
                records.pop_back();
            }
            else if (atom != "")
            {
                cur[atom] += max(count, 1);
                atom = "";
                count = 0;
            }
            if (isupper(formula[i]))
            {
                atom += formula[i];
            }
            else if (formula[i] == '(')
            {
                records.push_back(cur);
                cur = unordered_map<string, int>();
            }
            else
            {
                check = true;
            }
        }
        if (check)
        {
            count = max(count, 1);
            for (auto &[atom, num] : cur)
            {
                records.back()[atom] += num * count;
            }
            check = false;
            count = 0;
            cur = records.back();
            records.pop_back();
        }
        else if (atom != "")
        {
            cur[atom] += max(count, 1);
        }
        vector<string> atom_list;
        for (auto &p : cur)
        {
            atom_list.push_back(p.first);
        }
        sort(atom_list.begin(), atom_list.end());
        string res = "";
        for (auto atom : atom_list)
        {
            res += atom;
            if (cur[atom] > 1)
            {
                res += to_string(cur[atom]);
            }
        }
        return res;
    }
};
// @lc code=end
