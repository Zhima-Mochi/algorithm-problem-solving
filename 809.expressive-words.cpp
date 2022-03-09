/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int expressiveWords(string s, vector<string> &words)
    {
        int width_s = s.size();
        vector<pair<char, int>> record;
        int count = 0;
        char prev = 0;
        for (auto c : s)
        {
            if (c != prev)
            {
                if (count != 0)
                {
                    record.push_back({prev, count});
                }
                prev = c;
                count = 1;
            }
            else
            {
                ++count;
            }
        }
        record.push_back({prev, count});
        int res = 0;
        for (auto &&word : words)
        {
            int count = 0;
            char prev = 0;
            int comp_ind = 0;
            bool match = true;
            for (auto c : word)
            {
                if (c != prev)
                {
                    if (count != 0)
                    {
                        if (prev != record[comp_ind].first || count > record[comp_ind].second || (count != record[comp_ind].second && record[comp_ind].second == 2))
                        {
                            match = false;
                            break;
                        }
                        else
                        {
                            ++comp_ind;
                            if (comp_ind == record.size())
                            {
                                match = false;
                                break;
                            }
                            if (record[comp_ind].first != c)
                            {
                                match = false;
                                break;
                            }
                        }
                    }
                    prev = c;
                    count = 1;
                }
                else
                {
                    ++count;
                }
            }

            if (comp_ind != record.size() - 1)
            {
                match = false;
            }
            else if (prev != record[comp_ind].first || count > record[comp_ind].second || (count != record[comp_ind].second && record[comp_ind].second == 2))
            {
                match = false;
            }

            if (match)
            {
                ++res;
            }
        }
        return res;
    }
};
// @lc code=end