/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
    unordered_map<string, string> code2long, long2code;
    string select = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string getCode()
    {
        string res;
        for (int i = 0; i != 6; ++i)
        {
            res.push_back(select[rand() % select.size()]);
        }
        return res;
    }

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        if (long2code.count(longUrl))
        {
            return "https://tinyurl.com/" + long2code[longUrl];
        }
        else
        {
            string code = getCode();
            while (code2long.count(code))
            {
                code = getCode();
            }
            long2code[longUrl] = code;
            code2long[code] = longUrl;
            return "https://tinyurl.com/" + code;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return code2long[shortUrl.substr(shortUrl.find_last_of('/') + 1)];
    }
};
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
