/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */
#include <vector>
#include <queue>
#include <set>
using namespace std;
// @lc code=start
class KthLargest
{
public:
    KthLargest(int k, vector<int> &nums)
    {
        _k = k;
        for (auto &n : nums)
        {
            q.push(n);
            if (q.size() > _k)
            {
                q.pop();
            }
        }
    }

    int add(int val)
    {
        q.push(val);
        if (q.size() > _k)
        {
            q.pop();
        }
        return q.top();
    }
    priority_queue<int, vector<int>, greater<int>> q;
    int _k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
// class KthLargest
// {
// public:
//     KthLargest(int k, vector<int> &nums)
//     {
//         _k = k;
//         for (auto &n : nums)
//         {
//             s.insert(n);
//             if (s.size() > _k)
//             {
//                 s.erase(s.begin());
//             }
//         }
//     }

//     int add(int val)
//     {
//         s.insert(val);
//         if (s.size() > _k)
//         {
//             s.erase(s.begin());
//         }
//         return *s.begin();
//     }
//     multiset<int> s;
//     int _k;
// };