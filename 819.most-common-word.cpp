/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        int max_count = 0;
        string current_string;
        unordered_map<string, int> umap;
        unordered_set<string> uset(banned.begin(), banned.end());
        string res;
        paragraph.push_back(' ');
        int len = paragraph.size();
        int i = 0;
        while (i != len)
        {
            if (!isalpha(paragraph[i]))
            {
                if (!current_string.empty())
                {
                    ++umap[current_string];
                    if (!uset.count(current_string) && umap[current_string] > max_count)
                    {
                        max_count = umap[current_string];
                        if (res != current_string)
                        {
                            res = move(current_string);
                        }
                        else
                        {
                            current_string.clear();
                        }
                    }
                    else
                    {
                        current_string.clear();
                    }
                }
                while (i != len && !isalpha(paragraph[++i]))
                    ;
            }
            else
            {
                current_string.push_back(tolower(paragraph[i++]));
            }
        }
        return res;
    }
};
// @lc code=end
