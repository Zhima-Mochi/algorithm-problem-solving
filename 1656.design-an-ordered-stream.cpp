/*
 * @lc app=leetcode id=1656 lang=cpp
 *
 * [1656] Design an Ordered Stream
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class OrderedStream
{
    vector<string> input;
    int ptr = 0;
    int end_ptr;

public:
    OrderedStream(int n)
    {
        input.resize(n);
        end_ptr = n;
    }

    vector<string> insert(int idKey, string value)
    {
        input[idKey - 1] = value;
        vector<string> res;
        if (ptr == idKey - 1)
        {
            while (ptr != end_ptr && !input[ptr].empty())
            {
                res.push_back(input[ptr++]);
            }
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end
