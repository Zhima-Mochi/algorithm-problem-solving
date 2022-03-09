/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start

class Solution
{

public:
    static vector<string> phone_click;
    vector<string> letterCombinations(const string &digits)
    {
        if (digits.size() == 0)
        {
            return vector<string>();
        }
        vector<string> res = {""};

        for (auto d : digits)
        {
            auto len = res.size();

            auto &str = phone_click[d - '2'];

            vector<string> new_res;
            for (size_t i = 0; i != len; i++)
            {
                for (auto s : str)
                {

                    new_res.push_back(res[i] + s);
                }
                // If memory is limited, can remove element in res (should be modified to reverse direction)
            }
            res = new_res;
        }
        return res;
    }
};
vector<string> Solution::phone_click = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
// @lc code=end
