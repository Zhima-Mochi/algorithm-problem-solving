/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximumSwap(int num)
    {
        string num_str = to_string(num);
        int left = -1, right = -1;
        for (int i = 1, width = num_str.size(); i != width; ++i)
        {
            if (left == -1)
            {
                right = i - 1;
            }
            if (num_str[i] > num_str[right])
            {
                right = i;
                if (left == -1)
                {
                    left = right;
                }
                while (left > 0 && num_str[right] > num_str[left - 1])
                {
                    --left;
                }
            }
            else if (num_str[i] == num_str[right])
            {
                right = i;
            }
        }
        if (left != -1)
        {
            swap(num_str[left], num_str[right]);
        }
        return stoi(num_str);
    }
};
// @lc code=end
