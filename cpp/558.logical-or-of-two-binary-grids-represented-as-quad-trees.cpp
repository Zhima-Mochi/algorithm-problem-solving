/*
 * @lc app=leetcode id=558 lang=cpp
 *
 * [558] Logical OR of Two Binary Grids Represented as Quad-Trees
 */
#include <queue>
using namespace std;
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution
{
public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        auto root = new Node();
        dfs(root, quadTree1, quadTree2);
        return root;
    }
    void dfs(Node *cur, Node *cur1, Node *cur2)
    {
        if ((cur1 && cur1->isLeaf && cur1->val == 1) || (cur2 && cur2->isLeaf && cur2->val == 1))
        {
            cur->isLeaf = true;
            cur->val = 1;
            return;
        }
        else if ((!cur1 || cur1->isLeaf) && (!cur2 || cur2->isLeaf))
        {
            cur->isLeaf = true;
            cur->val = 0;
            return;
        }
        else
        {
            if (cur1 && cur1->topLeft || cur2 && cur2->topLeft)
            {
                cur->topLeft = new Node();
                dfs(cur->topLeft, cur1 ? cur1->topLeft : nullptr, cur2 ? cur2->topLeft : nullptr);
                cur->topRight = new Node();
                dfs(cur->topRight, cur1 ? cur1->topRight : nullptr, cur2 ? cur2->topRight : nullptr);
                cur->bottomLeft = new Node();
                dfs(cur->bottomLeft, cur1 ? cur1->bottomLeft : nullptr, cur2 ? cur2->bottomLeft : nullptr);
                cur->bottomRight = new Node();
                dfs(cur->bottomRight, cur1 ? cur1->bottomRight : nullptr, cur2 ? cur2->bottomRight : nullptr);
                if (cur->topLeft->isLeaf && cur->topRight->isLeaf && cur->bottomLeft->isLeaf && cur->bottomRight->isLeaf)
                {
                    if (cur->topLeft->val == cur->topRight->val && cur->topRight->val == cur->bottomLeft->val && cur->bottomLeft->val == cur->bottomRight->val)
                    {
                        cur->isLeaf = true;
                        cur->val = cur->topLeft->val;
                        delete (cur->topLeft);
                        delete (cur->topRight);
                        delete (cur->bottomLeft);
                        delete (cur->bottomRight);
                        cur->topLeft = cur->topRight = cur->bottomLeft = cur->bottomRight = nullptr;
                    }
                }
            }
        }
    }
};
// @lc code=end