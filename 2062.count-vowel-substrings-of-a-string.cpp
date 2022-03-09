/*
 * @lc app=leetcode id=2062 lang=cpp
 *
 * [2062] Count Vowel Substrings of a String
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
    string vowels = "aeiou";

public:
    int countVowelSubstrings(string word)
    {
        vector<int> vowel_pos(5, -1);
        int left_ind = -1;
        int ind = 0;
        int res = 0;
        for (auto c : word)
        {
            int type = vowels.find(c);
            if (type != -1)
            {
                if (left_ind == -1)
                {
                    left_ind = ind;
                }
                vowel_pos[type] = ind;
                int right_ind = *min_element(vowel_pos.begin(), vowel_pos.end());
                if (right_ind != -1)
                {
                    res += right_ind - left_ind + 1;
                }
            }
            else
            {
                left_ind = -1;
                vowel_pos = vector<int>(5, -1);
            }
            ++ind;
        }
        return res;
    }
};
// @lc code=end
