/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reformat(string s)
    {
        int width = s.size();
        if (width == 1)
        {
            return s;
        }
        int num_count = 0;
        for (auto c : s)
        {
            if (isdigit(c))
            {
                ++num_count;
            }
        }
        if (num_count != width / 2 && num_count != (width + 1) / 2)
        {
            return "";
        }
        bool num_first = num_count > width / 2;
        int left = 0;
        int right = width % 2 ? width - 2 : width - 1;
        while (left < width && right > -1)
        {
            if (num_first)
            {
                if (isdigit(s[left]))
                {
                    left += 2;
                    continue;
                }
                if (isalpha(s[right]))
                {
                    right -= 2;
                    continue;
                }
            }
            else
            {
                if (!isdigit(s[left]))
                {
                    left += 2;
                    continue;
                }
                if (!isalpha(s[right]))
                {
                    right -= 2;
                    continue;
                }
            }
            swap(s[left], s[right]);
            left += 2;
            right -= 2;
        }
        return s;
    }
};
// @lc code=end
