/*
 * @lc app=leetcode id=1860 lang=cpp
 *
 * [1860] Incremental Memory Leak
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> memLeak(int memory1, int memory2)
    {
        int n = 1;
        while (true)
        {
            if (memory1 >= memory2 && memory1 >= n)
            {
                memory1 -= n;
            }
            else if (memory2 >= n)
            {
                memory2 -= n;
            }
            else
            {
                break;
            }
            ++n;
        }
        return {n, memory1, memory2};
    }
};
// @lc code=end
