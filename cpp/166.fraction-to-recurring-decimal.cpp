/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string res;
        long numeratorL = static_cast<long>(numerator);
        long denominatorL = static_cast<long>(denominator);
        if (numeratorL * denominatorL < 0)
        {
            res.push_back('-');
        }
        numeratorL = abs(numeratorL);
        denominatorL = abs(denominatorL);

        res.append(to_string(numeratorL / denominatorL));
        numeratorL %= denominatorL;
        if (numeratorL == 0)
        {
            return res;
        }
        else
        {
            res.push_back('.');
        }
        unordered_map<long, int> umap;
        umap[numeratorL] = res.size();
        int cycle_index = -1;
        while (numeratorL)
        {
            numeratorL *= 10;
            res.push_back('0' + numeratorL / denominatorL);
            numeratorL %= denominatorL;
            if (umap.count(numeratorL))
            {
                cycle_index = umap[numeratorL];
                break;
            }
            else
            {
                umap[numeratorL] = res.size();
            }
        }
        if (cycle_index != -1)
        {
            res.insert(cycle_index, "(");
            res.push_back(')');
        }
        return res;
    }
};
// @lc code=end
//1\n214748364