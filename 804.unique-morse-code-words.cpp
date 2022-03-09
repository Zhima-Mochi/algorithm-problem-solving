/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    vector<string> code_map = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> uset;
        for (auto &word : words)
        {
            string codestring;
            for (auto c : word)
            {
                codestring.append(code_map[c - 'a']);
            }
            uset.insert(codestring);
        }
        return uset.size();
    }
};
// @lc code=end
