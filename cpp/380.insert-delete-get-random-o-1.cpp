/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
// @lc code=start
class RandomizedSet
{
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand(time(nullptr));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (umap.count(val))
        {
            return false;
        }
        else
        {
            umap[val] = vec.size();
            vec.push_back(val);
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (umap.count(val))
        {
            swap(vec.back(), vec[umap[val]]);
            umap[vec[umap[val]]] = umap[val];
            umap.erase(val);
            vec.pop_back();
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return vec[rand() % vec.size()];
    }

private:
    unordered_map<int, int> umap;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
