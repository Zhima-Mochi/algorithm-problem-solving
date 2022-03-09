/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string n_str = to_string(n);
        int width = n_str.size();
        int swap_pos_left = width - 2;
        while (swap_pos_left > -1)
        {
            if (n_str[swap_pos_left] < n_str[swap_pos_left + 1])
            {
                break;
            }
            --swap_pos_left;
        }
        if (swap_pos_left == -1)
        {
            return -1;
        }
        else
        {
            int swap_pos_right = width - 1;
            while (n_str[swap_pos_right] <= n_str[swap_pos_left])
            {
                --swap_pos_right;
            }
            swap(n_str[swap_pos_left], n_str[swap_pos_right]);
            reverse(n_str.begin() + swap_pos_left + 1, n_str.end());
            long res = stol(n_str);
            return res > INT_MAX ? -1 : res;
        }
    }
};
// @lc code=end
