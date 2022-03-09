/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0, right = letters.size() - 1;
        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (letters[mid] - target <= 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return letters[left] > target ? letters[left] : letters[0];
    }
};
// @lc code=end
