/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
#include <algorithm>
#include <set>

using namespace std;
// @lc code=start
class MyCalendar
{
    set<pair<int, int>> book_start;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        if (book_start.empty())
        {
            book_start.insert({start, end});
            return true;
        }
        auto lb = book_start.lower_bound({start, end});
        if (lb != book_start.end())
        {
            if (lb->first < end)
            {
                return false;
            }
        }
        if (lb != book_start.begin() && prev(lb)->second > start)
        {
            return false;
        }
        book_start.insert({start, end});

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

// class SegmentTreeNode
// {
// public:
//     SegmentTreeNode(int start, int end) : start(start), end(end)
//     {
//         contain = false;
//         left = right = nullptr;
//     }
//     int start, end;
//     SegmentTreeNode *left, *right;
//     bool contain;
//     static bool is_overlaped(int start, int end, SegmentTreeNode *node)
//     {
//         if (node->contain)
//         {
//             return true;
//         }
//         else
//         {
//             int mid = node->start + (node->end - node->start) / 2;
//             if (mid >= start)
//             {
//                 if (node->left && is_overlaped(start, min(mid, end), node->left))
//                 {
//                     return true;
//                 }
//             }
//             if (mid < end)
//             {
//                 if (node->right && is_overlaped(max(mid + 1, start), end, node->right))
//                 {
//                     return true;
//                 }
//             }
//             return false;
//         }
//     }
//     static void update_tree(int start, int end, SegmentTreeNode *node)
//     {
//         if (node->start == start && node->end == end)
//         {
//             node->contain = true;
//         }
//         else
//         {
//             int mid = node->start + (node->end - node->start) / 2;
//             if (mid >= start)
//             {
//                 if (!node->left)
//                 {
//                     node->left = new SegmentTreeNode(node->start, mid);
//                 }
//                 update_tree(start, min(mid, end), node->left);
//             }
//             if (mid < end)
//             {
//                 if (!node->right)
//                 {
//                     node->right = new SegmentTreeNode(mid + 1, node->end);
//                 }
//                 update_tree(max(mid + 1, start), end, node->right);
//             }
//         }
//     }
// };

// class MyCalendar
// {
//     SegmentTreeNode *root;

// public:
//     MyCalendar()
//     {
//         root = new SegmentTreeNode(0, 1000000000);
//     }

//     bool book(int start, int end)
//     {
//         if (SegmentTreeNode::is_overlaped(start, end - 1, root))
//         {
//             return false;
//         }
//         else
//         {
//             SegmentTreeNode::update_tree(start, end - 1, root);
//             return true;
//         }
//     }
// };
