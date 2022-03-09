/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};
// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, Employee *> umap;
        for (auto e : employees)
        {
            umap[e->id] = e;
        }
        int res = 0;
        res += umap[id]->importance;
        auto v = umap[id]->subordinates;
        while (!v.empty())
        {
            vector<int> next_v;
            for (auto &id : v)
            {
                res += umap[id]->importance;
                for (auto &sub_id : umap[id]->subordinates)
                {
                    next_v.push_back(sub_id);
                }
            }
            swap(v, next_v);
        }
        return res;
    }
};
// @lc code=end
