/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 */
#include <string>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        unordered_set<string> diff_num;
        int width = word.size();
        string digit_w;
        for (int i = 0; i != width; ++i)
        {
            if (isdigit(word[i]))
            {
                digit_w.push_back(word[i]);
            }
            else
            {
                if (digit_w != "")
                {
                    int non_zero_ind = digit_w.find_first_not_of("0");
                    if (non_zero_ind == -1)
                    {
                        diff_num.insert("0");
                    }
                    else
                    {
                        diff_num.insert(digit_w.substr(non_zero_ind));
                    }
                    digit_w.clear();
                }
            }
        }
        if (digit_w != "")
        {
            int non_zero_ind = digit_w.find_first_not_of("0");
            if (non_zero_ind == -1)
            {
                diff_num.insert("0");
            }
            else
            {
                diff_num.insert(digit_w.substr(non_zero_ind));
            }
        }
        return diff_num.size();
    }
};
// @lc code=end
