/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int width = primes.size();
        vector<int> accum = {1, primes[0]};
        vector<int> curPos(width, 1);
        vector<int> nextVal = primes;
        for (int k = 1; k != n; ++k)
        {
            auto minVal = INT_MAX;
            for (int i = 0; i != width; ++i)
            {
                if (accum.back() == nextVal[i])
                {
                    nextVal[i] = accum[curPos[i]++] * primes[i];
                }
                minVal = min(nextVal[i], minVal);
            }
            accum.push_back(minVal);
        }
        return accum[n - 1];
    }
};
// @lc code=end

//slow
// class Solution
// {
// public:
//     int nthSuperUglyNumber(int n, vector<int> &primes)
//     {
//         int width = primes.size();
//         vector<int> accum = {1};
//         vector<int> curPos(width, 0);
//         int nextVal = primes[0];
//         for (int k = 1; k != n; ++k)
//         {
//             accum.push_back(nextVal);
//             auto next_nextVal = INT_MAX;
//             for (int i = 0; i != width; ++i)
//             {
//                 auto val = accum[curPos[i]] * primes[i];
//                 if (accum[curPos[i]] * primes[i] == nextVal)
//                 {
//                     val = primes[i] * accum[++curPos[i]];
//                 }
//                 next_nextVal = min(val, next_nextVal);
//             }
//             nextVal = next_nextVal;
//         }
//         return accum[n - 1];
//     }
// };