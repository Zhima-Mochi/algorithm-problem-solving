/*
 * @lc app=leetcode id=816 lang=cpp
 *
 * [816] Ambiguous Coordinates
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> ambiguousCoordinates(string s)
    {
        vector<string> res;
        int width = s.size();
        for (auto i = 1; i != width - 2; ++i)
        {
            string a;
            string b;
            vector<string> a_collection;
            vector<string> b_collection;
            for (int j = 1; j != i + 1; ++j)
            {
                if (j != 1)
                {
                    if (s[i] == '0')
                    {
                        break;
                    }
                    if (j == 3 && s[1] == '0' && s[2] == '0')
                    {
                        break;
                    }
                    a = s.substr(1, j - 1) + '.' + s.substr(j, i + 1 - j);
                }
                else
                {
                    a = s.substr(1, i);
                }
                if (check_valid(a))
                {
                    a_collection.push_back(a);
                }
            }
            for (int k = i + 1; k != width - 1; ++k)
            {
                if (k != i + 1)
                {
                    if (s[width - 1] == '0')
                    {
                        break;
                    }
                    if (k == i + 3 && s[i + 1] == '0' && s[i + 2] == '0')
                    {
                        break;
                    }
                    b = s.substr(i + 1, k - i - 1) + '.' + s.substr(k, width - 1 - k);
                }
                else
                {
                    b = s.substr(i + 1, width - 2 - i);
                }
                if (check_valid(b))
                {
                    b_collection.push_back(b);
                }
            }
            for (auto &&a : a_collection)
            {
                for (auto &&b : b_collection)
                {
                    res.push_back('(' + a + ", " + b + ')');
                }
            }
        }
        return res;
    }
    bool check_valid(string s)
    {
        int point_pos = s.find('.');
        if (point_pos == -1)
        {
            if (s.size() > 1 && s[0] == '0')
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        if (point_pos == 0 || point_pos == s.size() - 1)
        {
            return false;
        }
        else if (s.back() == '0')
        {
            return false;
        }
        else if (s[0] == '0' && point_pos != 1)
        {
            return false;
        }

        return true;
    }
};
// @lc code=end
