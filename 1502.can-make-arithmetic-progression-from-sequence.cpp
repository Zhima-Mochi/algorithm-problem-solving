/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
// T:O(N) S:O(1)
class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        int min_val = arr[0], max_val = arr[0];
        for (auto n : arr)
        {
            if (n < min_val)
            {
                min_val = n;
            }
            else if (n > max_val)
            {
                max_val = n;
            }
        }
        int width = arr.size();
        if ((max_val - min_val) % (width - 1))
        {
            return false;
        }
        int diff = (max_val - min_val) / (width - 1);
        if (diff == 0)
        {
            return true;
        }
        for (auto n : arr)
        {
            if (n > 1000000)
            {
                n -= 3000000;
            }
            if ((n - min_val) % diff)
            {
                return false;
            }
            int pos = (n - min_val) / diff;
            if (pos >= width || arr[pos] > 1000000)
            {
                return false;
            }
            arr[pos] += 3000000;
        }
        return true;
    }
};
// @lc code=end
