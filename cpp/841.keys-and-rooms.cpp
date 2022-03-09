/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */
#include <vector>
using namespace std;

// @lc code=start
// t:O(N+sum(all keys)) s:O(N)
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<int> record(n);
        record[0] = 1;
        vector<int> st = {{0}};
        while (!st.empty())
        {
            int room_id=st.back();
            st.pop_back();
            for (auto idx : rooms[room_id])
            {
                if (record[idx] == 0)
                {
                    st.push_back(idx);
                    record[idx] = 1;
                }
            }
        }
        for (auto l : record)
        {
            if (l == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
