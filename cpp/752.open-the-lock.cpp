/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    unordered_set<string> deadends_set;

public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_map<string, int> status_record_1, status_record_2;
        queue<string> status_queue_1, status_queue_2;
        if (target == "0000")
        {
            return 0;
        }
        else
        {
            status_queue_1.push("0000");
            status_queue_2.push(target);
        }
        for (auto &deadend : deadends)
        {
            deadends_set.insert(deadend);
        }
        if (deadends_set.count("0000"))
        {
            return -1;
        }
        while (!status_queue_1.empty() and !status_queue_2.empty())
        {
            int t;
            if (status_queue_1.size() <= status_queue_2.size())
            {
                t = search(status_queue_1, status_record_1, status_record_2);
            }
            else
            {
                t = search(status_queue_2, status_record_2, status_record_1);
            }
            if (t != -1)
            {
                return t;
            }
        }
        return -1;
    }
    int search(queue<string> &status_queue, unordered_map<string, int> &cur, unordered_map<string, int> &other)
    {
        string current_status = status_queue.front();
        status_queue.pop();
        int step = cur[current_status];
        for (int i = 0; i != 4; ++i)
        {
            for (int j = -1; j <= 1; j += 2)
            {
                string new_status = current_status;
                new_status[i] = current_status[i] + j;
                if (new_status[i] > '9')
                {
                    new_status[i] = '0';
                }
                if (new_status[i] < '0')
                {
                    new_status[i] = '9';
                }
                if (deadends_set.count(new_status) || cur.count(new_status))
                {
                    continue;
                }
                if (other.count(new_status))
                {
                    return step + 1 + other[new_status];
                }
                else
                {
                    status_queue.push(new_status);
                    cur[new_status] = step + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

// class Solution
// {
// public:
//     int openLock(vector<string> &deadends, string target)
//     {
//         unordered_set<string> deadends_set;
//         queue<string> status_queue;
//         if (target == "0000")
//         {
//             return 0;
//         }
//         else
//         {
//             status_queue.push("0000");
//         }
//         for (auto &deadend : deadends)
//         {
//             deadends_set.insert(deadend);
//         }
//         if (deadends_set.count("0000"))
//         {
//             return -1;
//         }
//         int res = 0;
//         while (!status_queue.empty())
//         {
//             int status_len = status_queue.size();
//             while (status_len--)
//             {
//                 string current_status = status_queue.front();
//                 status_queue.pop();
//                 if (current_status == target)
//                 {
//                     return res;
//                 }
//                 for (int i = 0; i != 4; ++i)
//                 {
//                     string new_status = current_status;
//                     if (current_status[i] == target[i])
//                     {
//                         new_status[i] = target[i] + 1;
//                         if (new_status[i] > '9')
//                         {
//                             new_status[i] = '0';
//                         }
//                         if (!deadends_set.count(new_status))
//                         {
//                             status_queue.push(new_status);
//                             deadends_set.insert(new_status);
//                         }
//                         new_status[i] = target[i] - 1;
//                         if (new_status[i] < '0')
//                         {
//                             new_status[i] = '9';
//                         }
//                         if (!deadends_set.count(new_status))
//                         {
//                             status_queue.push(new_status);
//                             deadends_set.insert(new_status);
//                         }
//                     }
//                     else if (current_status[i] == '0')
//                     {
//                         new_status[i] = '1';
//                         if (!deadends_set.count(new_status))
//                         {
//                             status_queue.push(new_status);
//                             deadends_set.insert(new_status);
//                         }
//                         new_status[i] = '9';
//                         if (!deadends_set.count(new_status))
//                         {
//                             status_queue.push(new_status);
//                             deadends_set.insert(new_status);
//                         }
//                     }
//                     else if (current_status[i] > target[i])
//                     {
//                         new_status[i] -= 1;
//                         if (!deadends_set.count(new_status))
//                         {
//                             status_queue.push(new_status);
//                             deadends_set.insert(new_status);
//                         }
//                     }
//                     else
//                     {
//                         new_status[i] += 1;
//                         if (!deadends_set.count(new_status))
//                         {
//                             status_queue.push(new_status);
//                             deadends_set.insert(new_status);
//                         }
//                     }
//                 }
//             }
//             ++res;
//         }
//         return -1;
//     }
// };