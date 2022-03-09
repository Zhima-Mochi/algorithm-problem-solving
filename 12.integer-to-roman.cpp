/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include <string>
#include <map>
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
class Solution
{
    static vector<pair<int, char>> dict;
    static int dict_len;

public:
    string intToRoman(int num)
    {
        string res;
        for (int i = dict_len - 1; i != -1; i--)
        {
            int divisor = dict[i].first;
            int quotient = num / divisor;
            num %= divisor;
            if (quotient == 0)
            {
                continue;
            }
            else if (quotient <= 3)
            {
                res.insert(res.end(), quotient, dict[i].second);
            }
            else
            {
                //e.g. VIIII res="V"
                if (res.back() == dict[i + 1].second)
                {
                    //res=""
                    res.pop_back();
                    //res=="I"
                    res.push_back(dict[i].second);
                    //res=="IX"
                    res.push_back(dict[i + 2].second);
                }
                //e.g. IIII res=""
                else
                {
                    //res="I"
                    res.push_back(dict[i].second);
                    //res="IV"
                    res.push_back(dict[i + 1].second);
                }
            }
            if (num == 0)
            {
                return res;
            }
        }
        return res;
    }
};
vector<pair<int, char>> Solution::dict = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};
int Solution::dict_len = Solution::dict.size();
// @lc code=end
