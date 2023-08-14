/*
 * @lc app=leetcode id=2092 lang=cpp
 *
 * [2092] Find All People With Secret
 */
#include <vector>
#include <map>
#include <unordered_set>
#include <numeric>
using namespace std;
// @lc code=start
// t:O(mlogm+n), s:O(m+n)
class Solution
{
public:
    int get_group_idx(vector<int> &group_map, int person)
    {
        if (group_map[person] != person)
        {
            group_map[person] = get_group_idx(group_map, group_map[person]);
        }
        return group_map[person];
    }
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        map<int, vector<vector<int>>> mp;
        for (auto &meet : meetings)
        {
            mp[meet[2]].push_back({meet[0], meet[1]});
        }
        unordered_set<int> has_key_set;
        has_key_set.insert(0);
        has_key_set.insert(firstPerson);
        vector<int> group_map(n);
        iota(group_map.begin(), group_map.end(), 0);
        for (auto p : has_key_set)
        {
            group_map[p] = 0;
        }
        for (auto &[time, meets] : mp)
        {
            unordered_set<int> appear;
            for (auto &meet : meets)
            {
                appear.insert(meet[0]);
                appear.insert(meet[1]);
                int a = get_group_idx(group_map, meet[0]);
                int b = get_group_idx(group_map, meet[1]);
                if (a < b)
                {
                    group_map[b] = a;
                }
                else
                {
                    group_map[a] = b;
                }
            }

            for (auto p : appear)
            {
                if (get_group_idx(group_map, p) == 0)
                {
                    has_key_set.insert(p);
                }
            }
            for (auto p : appear)
            {
                if (!has_key_set.count(p))
                {
                    group_map[p] = p;
                }
            }
        }
        vector<int> res;
        for (auto p : has_key_set)
        {
            res.push_back(p);
        }
        return res;
    }
};
// @lc code=end
