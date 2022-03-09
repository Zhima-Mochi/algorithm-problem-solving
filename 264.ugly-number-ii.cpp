/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{

public:
    int nthUglyNumber(int n)
    {
        if (n <= 6)
        {
            return n;
        }
        vector<int> ug_nums = {1};
        int ind_2 = 0,
            ind_3 = 0, ind_5 = 0;
        while (ug_nums.size() != n - 1)
        {
            int next = min(ug_nums[ind_2] * 2, min(ug_nums[ind_3] * 3, ug_nums[ind_5] * 5));
            if (next == ug_nums[ind_2] * 2)
            {
                ++ind_2;
            }
            if (next == ug_nums[ind_3] * 3)
            {
                ++ind_3;
            }
            if (next == ug_nums[ind_5] * 5)
            {
                ++ind_5;
            }
            ug_nums.push_back(next);
        }
        return min(ug_nums[ind_2] * 2, min(ug_nums[ind_3] * 3, ug_nums[ind_5] * 5));
    }
};
// @lc code=end
// class Solution
// {

// public:
//     int nthUglyNumber(int n)
//     {
//         if (n <= 6)
//         {
//             return n;
//         }
//         int count = 1;
//         int res = 1;
//         priority_queue<int, vector<int>, greater<int>> q2, q3, q5;
//         q2.push(1);
//         q3.push(1);
//         q5.push(1);
//         while (count != n)
//         {
//             res = min(q2.top() * 2, min(q3.top() * 3, q5.top() * 5));
//             if (res == q2.top() * 2)
//             {
//                 q2.pop();
//             }
//             if (res == q3.top() * 3)
//             {
//                 q3.pop();
//             }
//             if (res == q5.top() * 5)
//             {
//                 q5.pop();
//             }
//             q2.push(res);
//             q3.push(res);
//             q5.push(res);
//             ++count;
//         }
//         return res;
//     }
// };