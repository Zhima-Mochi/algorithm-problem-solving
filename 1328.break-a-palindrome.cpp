/*
 * @lc app=leetcode id=1328 lang=cpp
 *
 * [1328] Break a Palindrome
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        int len = palindrome.size();
        if (len == 1)
        {
            return "";
        }
        int pos = palindrome.find_first_not_of('a');
        if (pos == -1 || (len % 2) && pos == len / 2)
        {
            palindrome.pop_back();
            palindrome.push_back('b');
        }
        else
        {
            palindrome[pos] = 'a';
        }
        return palindrome;
    }
};
// @lc code=end
