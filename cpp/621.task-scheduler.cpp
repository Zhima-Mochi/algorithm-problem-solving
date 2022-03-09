/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
        {
            return tasks.size();
        }
        int seen_count[26] = {0};
        for (auto c : tasks)
        {
            ++seen_count[c - 'A'];
        }

        int max_count = *max_element(begin(seen_count), end(seen_count));
        int max_count_num = 0;
        for (auto n : seen_count)
        {
            if (n == max_count)
            {
                ++max_count_num;
            }
        }
        return max(static_cast<int>(tasks.size()), (max_count - 1) * (n + 1) + max_count_num);
    }
};
// @lc code=end
// class Solution
// {
// public:
//     int leastInterval(vector<char> &tasks, int n)
//     {
//         int count[26] = {0};
//         for (auto c : tasks)
//         {
//             ++count[c - 'A'];
//         }

//         priority_queue<int> task_queue;
//         for (int i = 0; i != 26; ++i)
//         {
//             if (count[i] > 0)
//             {
//                 task_queue.push(count[i]);
//             }
//         }

//         vector<int> waiting_queue(n);
//         int waiting_queue_pos = 0;
//         int waiting_task_num = 0;
//         int res = 0;
//         while (!task_queue.empty() || waiting_task_num > 0)
//         {
//             ++res;
//             if (!task_queue.empty())
//             {
//                 auto pick = task_queue.top();
//                 task_queue.pop();
//                 if (n > 0)
//                 {
//                     auto pick_waiting = waiting_queue[waiting_queue_pos];

//                     if (pick_waiting > 0)
//                     {
//                         waiting_task_num -= 1;
//                         task_queue.push(pick_waiting);
//                     }
//                     if (pick > 1)
//                     {
//                         pick -= 1;
//                         waiting_task_num += 1;
//                         waiting_queue[waiting_queue_pos++] = pick;
//                         waiting_queue_pos %= n;
//                     }
//                     else
//                     {
//                         waiting_queue[waiting_queue_pos++] = 0;
//                         waiting_queue_pos %= n;
//                     }
//                 }
//                 else
//                 {
//                     if (pick > 1)
//                     {
//                         pick -= 1;
//                         task_queue.push(pick);
//                     }
//                 }
//             }
//             else
//             {
//                 auto pick_waiting = waiting_queue[waiting_queue_pos];
//                 if (pick_waiting > 0)
//                 {
//                     waiting_task_num -= 1;
//                     task_queue.push(pick_waiting);
//                 }
//                 waiting_queue[waiting_queue_pos++] = 0;
//                 waiting_queue_pos %= n;
//             }
//         }
//         return res;
//     }
// };