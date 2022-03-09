/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
    int w;

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        w = beginWord.size();
        unordered_set<string> begin_set, list;
        for (auto &w : wordList)
        {
            list.insert(w);
        }
        if (!list.count(endWord))
        {
            return 0;
        }
        begin_set.insert(beginWord);
        int turn = 1;
        while (begin_set.size())
        {
            ++turn;
            unordered_set<string> next_set;
            for (auto &begin_str : begin_set)
            {
                unordered_set<string> collect_set;
                for (auto &list_str : list)
                {
                    if (check(list_str, begin_str))
                    {
                        if (list_str == endWord)
                        {
                            return turn;
                        }
                        collect_set.insert(list_str);
                    }
                }
                for (auto &collect_str : collect_set)
                {
                    next_set.insert(collect_str);
                    list.erase(collect_str);
                }
            }
            begin_set = move(next_set);
        }
        return 0;
    }
    bool check(const string &l, const string &r)
    {
        int diff = 0;
        for (int i = 0; i != w; ++i)
        {
            if (l[i] != r[i])
            {
                ++diff;
                if (diff > 1)
                {
                    return false;
                }
            }
        }
        return diff == 1;
    }
};
// @lc code=end
