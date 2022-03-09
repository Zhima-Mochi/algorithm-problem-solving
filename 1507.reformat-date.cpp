/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<string, int> month_to_num = unordered_map<string, int>(
        {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}});

public:
    string reformatDate(string date)
    {
        int d = 0;

        for (auto c : date)
        {
            if (isdigit(c))
            {
                d *= 10;
                d += c - '0';
            }
            else
            {
                break;
            }
        }
        string day = '0' + to_string(d);
        string month = '0' + to_string(month_to_num[date.substr(date.find_first_of(' ') + 1, 3)]);

        return date.substr(date.size() - 4) + '-' + month.substr(month.size() - 2) + '-' + day.substr(day.size() - 2);
    }
};
// @lc code=end
