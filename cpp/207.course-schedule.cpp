/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> require(numCourses);
        for (auto &pair : prerequisites)
        {
            require[pair[0]].push_back(pair[1]);
        }
        vector<bool> is_cycle(numCourses, false), to_pass(numCourses, false);
        for (int i = 0; i != numCourses; ++i)
        {
            if (!check_non_cycle(is_cycle, to_pass, i, require))
                return false;
        }
        return true;

        // unordered_map<int, unordered_set<int>> require;
        // vector<int> pick_times(numCourses, 0);
        // for (auto &pair : prerequisites)
        // {
        //     require[pair[0]].insert(pair[1]);
        //     ++pick_times[pair[1]];
        // }
        // for (int i = 0; i != numCourses; ++i)
        // {
        //     auto zero_pick = find(pick_times.begin(), pick_times.end(), 0);
        //     if (zero_pick == pick_times.end())
        //     {
        //         return false;
        //     }else{
        //         --pick_times[zero_pick-pick_times.begin()];
        //         for(auto & les: require[zero_pick-pick_times.begin()]){
        //             --pick_times[les];
        //         }
        //     }
        // }
        // return true;
    }
    bool check_non_cycle(vector<bool> &is_cycle, vector<bool> &to_pass, int lesson, vector<vector<int>> &require)
    {
        if (is_cycle[lesson])
        {
            return false;
        }
        if (to_pass[lesson])
        {
            return true;
        }
        is_cycle[lesson] = to_pass[lesson] = true;
        for (auto &les : require[lesson])
        {
            if (!check_non_cycle(is_cycle, to_pass, les, require))
                return false;
        }
        is_cycle[lesson] = false;
        return true;
    }
};
// @lc code=end
//4\n[[0,1],[2,3],[1,2],[3,0]]\n2\n[[1,0],[0,1]]