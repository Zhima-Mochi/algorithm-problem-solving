/*
 * @lc app=leetcode id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        vector<int> tasks_stack;
        vector<int> tasks_exc_time(n);
        int run_time = 0;
        for (auto &log : logs)
        {
            int task_num = stoi(log.substr(0, log.find_first_of(':')));
            int time_num = stoi(log.substr(log.find_last_of(':') + 1));
            string status = log.substr(log.find_first_of(':') + 1, log.find_last_of(':') - log.find_first_of(':') - 1);
            if (status == "start")
            {
                if (!tasks_stack.empty())
                {
                    tasks_exc_time[tasks_stack.back()] += time_num - run_time;
                }
                tasks_stack.push_back(task_num);
                run_time = time_num;
            }
            else
            {
                tasks_exc_time[task_num] += time_num - run_time + 1;
                tasks_stack.pop_back();
                run_time = time_num + 1;
            }
        }
        return tasks_exc_time;
    }
};
// @lc code=end
