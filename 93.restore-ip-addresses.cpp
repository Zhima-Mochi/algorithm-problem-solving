/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        int len = s.size();
        if (len < 4 || len > 12)
        {
            return res;
        }
        queue<string> collection;
        collection.push("");
        auto count = 4;
        while (!collection.empty() && count--)
        {
            int collection_len = collection.size();
            while (collection_len--)
            {
                auto current_ip = collection.front();
                collection.pop();
                int next_ip_pos = current_ip.size() - (3 - count);
                auto minimum_len = max(1, len - next_ip_pos - count * 3);
                auto maximum_len = len - next_ip_pos - count;
                if (s[next_ip_pos] == '0')
                {
                    if (minimum_len == 1)
                    {
                        collection.push(current_ip + ".0");
                    }
                    continue;
                }
                auto value = stoi(s.substr(next_ip_pos, minimum_len));
                while (value <= 255 && minimum_len <= maximum_len)
                {
                    collection.push(current_ip + '.' + to_string(value));
                    value *= 10;
                    value += s[next_ip_pos + minimum_len] - '0';
                    ++minimum_len;
                }
            }
        }
        while (!collection.empty())
        {
            res.push_back(collection.front().substr(1));
            collection.pop();
        }
        return res;
    }
};
// @lc code=end
