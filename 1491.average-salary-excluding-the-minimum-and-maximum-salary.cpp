/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution
{
public:
    double average(vector<int> &salary)
    {
        int sum_val = 0;
        int max_salary = salary[0], min_salary = salary[0];
        for (auto n : salary)
        {
            sum_val += n;
            if (n > max_salary)
            {
                max_salary = n;
            }
            else if (n < min_salary)
            {
                min_salary = n;
            }
        }
        sum_val -= (max_salary + min_salary);
        return static_cast<double>(sum_val) / (salary.size() - 2);
    }
};
// @lc code=end
