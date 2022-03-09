/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        //We can proof when index I (W.L.O.G. assume it is left_index) shift, there is no index X in (I, right_index) such that  ( X - I ) * height(I) is larger than (right_index - I) * height(I). Trivial.
        size_t left_index = 0;
        auto right_index = height.size() - 1;
        int maximum = 0;
        while (left_index != right_index)
        {
            int capacity;
            if (height[left_index] < height[right_index])
            {
                capacity = height[left_index] * (right_index - left_index);
                left_index++;
            }
            else
            {
                capacity = height[right_index] * (right_index - left_index);

                right_index--;
            }
            if (maximum < capacity)
            {
                maximum = capacity;
            }
        }
        return maximum;

        // int maximum_capacity = 0;
        // auto len = height.size();
        // for (size_t i = 0; i != len - 1; i++)
        // {
        //     if (height[i] == 0)
        //     {
        //         continue;
        //     }
        //     for (size_t j = len - 1, lower_bound = i + maximum_capacity / height[i]; j > lower_bound; j--)
        //     {
        //         if (height[j] >= height[i])
        //         {
        //             maximum_capacity = height[i] * (j - i);
        //             break;
        //         }
        //     }
        // }

        // for (size_t i = len - 1; i != -1; i--)
        // {
        //     if (height[i] == 0)
        //     {
        //         continue;
        //     }
        //     if(i <= maximum_capacity / height[i]){
        //         continue;
        //     }
        //     size_t upper_bound = i - maximum_capacity / height[i];

        //     for (size_t j = 0 ;j < upper_bound; j++)
        //     {
        //         if (height[j] >= height[i])
        //         {
        //             maximum_capacity = height[i] * (i - j);
        //             break;
        //         }
        //     }
        // }
        // return maximum_capacity;
    }
};
// @lc code=end
