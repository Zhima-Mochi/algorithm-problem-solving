/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
#include <vector>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if(node==nullptr){
            return nullptr;
        }
        vector<Node *> vec(100);
        vec[node->val - 1] = new Node(node->val);
        vector<Node *> next_collection = {node};
        while (!next_collection.empty())
        {
            auto cur = next_collection.back();
            next_collection.pop_back();
            if (!vec[cur->val - 1]->neighbors.empty())
            {
                continue;
            }
            for (auto nb : cur->neighbors)
            {
                if (vec[nb->val - 1] == nullptr)
                {
                    vec[nb->val - 1] = new Node(nb->val);
                    vec[cur->val - 1]->neighbors.push_back(vec[nb->val - 1]);
                    next_collection.push_back(nb);
                }
                else
                {
                    vec[cur->val - 1]->neighbors.push_back(vec[nb->val - 1]);
                }
            }
        }
        return vec[0];
        // auto clone_node = new Node(node->val);
        // vector<Node *> next_collection = {node};
        // vector<Node *> finish_collection;
        // vector<Node *> clone_next_collection = {clone_node};
        // vector<Node *> clone_finish_collection;
        // while (!next_collection.empty())
        // {
        //     auto cur = next_collection.back();
        //     auto clone_cur = clone_next_collection.back();
        //     finish_collection.push_back(cur);
        //     clone_finish_collection.push_back(clone_cur);
        //     next_collection.pop_back();
        //     clone_next_collection.pop_back();
        //     if (find(finish_collection.begin(), finish_collection.end(), cur) != finish_collection.end() || find(next_collection.begin(), next_collection.end(), cur) != next_collection.end())
        //     {
        //         continue;
        //     }
        //     for (auto nb : cur->neighbors)
        //     {
        //         auto exist_node = find(finish_collection.begin(), finish_collection.end(), nb);
        //         if (exist_node != finish_collection.end())
        //         {
        //             clone_cur->neighbors.push_back(*(clone_finish_collection.begin() + (exist_node - finish_collection.begin())));
        //             continue;
        //         }

        //         auto exist_collection_node = find(next_collection.begin(), next_collection.end(), nb);
        //         if (exist_collection_node != next_collection.end())
        //         {
        //             clone_cur->neighbors.push_back(*(clone_next_collection.begin() + (exist_collection_node - next_collection.begin())));
        //             continue;
        //         }

        //         next_collection.push_back(nb);
        //         clone_cur->neighbors.push_back(new Node(nb->val));
        //         clone_next_collection.push_back(clone_cur->neighbors.back());
        //     }
        // }
        // return clone_node;
    }
};
// @lc code=end
