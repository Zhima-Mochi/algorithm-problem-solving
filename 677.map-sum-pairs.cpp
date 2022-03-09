/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class MapSum;
class TrieNode
{
public:
    TrieNode() = default;
    friend class MapSum;

private:
    int val = 0;
    vector<TrieNode *> children = vector<TrieNode *>(26);
};
class MapSum
{
public:
    /** Initialize your data structure here. */
    MapSum() : root(new TrieNode())
    {
    }

    void insert(string key, int val)
    {
        auto cur = root;
        for (auto w : key)
        {
            if (!cur->children[w - 'a'])
            {
                cur->children[w - 'a'] = new TrieNode();
            }
            cur = cur->children[w - 'a'];
        }
        cur->val = val;
    }

    int sum(string prefix)
    {
        auto cur = root;
        for (auto w : prefix)
        {
            if (!cur->children[w - 'a'])
            {
                return 0;
            }
            cur = cur->children[w - 'a'];
        }
        return postOrder(cur);
    }
    TrieNode *root;
    int postOrder(TrieNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int total = root->val;
        for (auto child : root->children)
        {
            total += postOrder(child);
        }
        return total;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
