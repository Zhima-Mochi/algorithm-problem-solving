/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */
using namespace std;
// @lc code=start
class Solution
{
    double record[200][200] = {};

public:
    double soupServings(int n)
    {
        if (n >= 5000)
        {
            return 1;
        }
        return helpler((n + 24) / 25, (n + 24) / 25);
    }
    double helpler(int a, int b)
    {
        if (b < 0)
        {
            b = 0;
        }
        if (a < 0)
        {
            a = 0;
        }
        if (record[a][b] > 0)
        {
            return record[a][b];
        }
        if (a == 0 && b == 0)
        {
            return 0.5;
        }
        else if (a == 0)
        {
            return 1;
        }
        else if (b == 0)
        {
            return 0;
        }
        double res = 0;
        res += 0.25 * (helpler(a - 4, b) + helpler(a - 3, b - 1) + helpler(a - 2, b - 2) + helpler(a - 1, b - 3));
        record[a][b] = res;
        return res;
    }
};
// @lc code=end
