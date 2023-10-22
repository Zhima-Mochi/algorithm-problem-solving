/*
 * @lc app=leetcode id=2525 lang=cpp
 *
 * [2525] Categorize Box According to Criteria
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool isBulky = (max({length, width, height}) >= 10000) || (1000000000 * 1.0 / length / width / height) <= 1;
        bool isHeavy = mass >= 100;
        if (isBulky && isHeavy)
        {
            return "Both";
        }
        else if (isBulky)
        {
            return "Bulky";
        }
        else if (isHeavy)
        {
            return "Heavy";
        }
        return "Neither";
    }
};
// @lc code=end
