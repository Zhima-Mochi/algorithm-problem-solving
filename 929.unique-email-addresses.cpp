/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> res;
        for (auto &email : emails)
        {
            string address;
            int pos = 0;
            while (email[pos] != '+' && email[pos] != '@')
            {
                if (email[pos] == '.')
                {
                    ++pos;
                    continue;
                }
                address.push_back(email[pos]);
                ++pos;
            }
            while (email[pos] != '@')
            {
                ++pos;
            }
            address.append(email.substr(pos));
            res.insert(address);
        }
        return res.size();
    }
};
// @lc code=end
