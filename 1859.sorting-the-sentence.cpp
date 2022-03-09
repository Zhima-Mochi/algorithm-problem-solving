/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    string sortSentence(string s)
    {
        vector<string> record(201);
        string word = "";
        int pos = 0;
        for (auto c : s)
        {
            if (isalpha(c))
            {
                word.push_back(c);
            }
            else if (isdigit(c))
            {
                pos *= 10;
                pos += c - '0';
            }
            else
            {
                record[pos] = word;
                word = "";
                pos = 0;
            }
        }
        record[pos] = word;

        string res;
        for (int i = 1; i != 201; ++i)
        {
            if (record[i].length())
            {
                res.append(record[i]);
                res.push_back(' ');
            }
            else
            {
                break;
            }
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
