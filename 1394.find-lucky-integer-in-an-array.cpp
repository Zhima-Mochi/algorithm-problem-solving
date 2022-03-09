/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        vector<int> vec(501);
        for (auto n : arr)
        {
            ++vec[n];
        }
        for (int i = 500; i != 0; --i)
        {
            if (vec[i] == i)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
