/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class LRUCache
{
public:
    LRUCache(int capacity)
        : s(capacity)
    {
    }

    int get(int key)
    {
        clean();
        if (umap.count(key))
        {
            q.push(key);
            ++keyLife[key];
            while (q.front() == key && keyLife[key])
            {
                q.pop();
                --keyLife[key];
            }
            return umap[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        clean();
        if (umap.count(key))
        {
            q.push(key);
            ++keyLife[key];
            umap[key] = value;
            while (q.front() == key && keyLife[key])
            {
                q.pop();
                --keyLife[key];
            }
        }
        else
        {
            q.push(key);
            ++current_size;
            umap[key] = value;
        }
    }

private:
    int s;
    int current_size = 0;
    queue<int> q;
    unordered_map<int, int> umap;
    unordered_map<int, int> keyLife;
    void clean()
    {
        while (current_size > s)
        {
            if (!keyLife[q.front()])
            {
                umap.erase(q.front());
                --current_size;
            }
            else
            {
                --keyLife[q.front()];
            }
            q.pop();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


// class LRUCache
// {
// public:
//     LRUCache(int capacity)
//         : s(capacity)
//     {
//     }

//     int get(int key)
//     {
//         if (umap.count(key))
//         {
//             if (ls.back() != key)
//             {
//                 ls.erase(umap[key].second);
//                 ls.push_back(key);
//                 umap[key].second = prev(ls.end());
//             }
//             return umap[key].first;
//         }
//         else
//         {
//             return -1;
//         }
//     }

//     void put(int key, int value)
//     {
//         if (umap.count(key))
//         {
//             if (ls.back() != key)
//             {
//                 ls.erase(umap[key].second);
//                 ls.push_back(key);
//                 umap[key] = {value, prev(ls.end())};
//             }
//             umap[key].first = value;
//         }
//         else
//         {
//             if (ls.size() == s)
//             {
//                 umap.erase(*(ls.begin()));
//                 ls.pop_front();
//             }
//             ls.push_back(key);
//             umap[key] = {value, prev(ls.end())};
//         }
//     }

// private:
//     using value_iter = pair<int, list<int>::iterator>;
//     int s;
//     list<int> ls;
//     unordered_map<int, value_iter> umap;
// };