/*
 * @lc app=leetcode id=2424 lang=cpp
 *
 * [2424] Longest Uploaded Prefix
 */
#include <vector>
using namespace std;
// @lc code=start
// t: O(n), s: O(n)
class LUPrefix
{
    vector<bool> videos;
    int curr = 1;
    int bound = 0;

public:
    LUPrefix(int n)
    {
        videos.resize(n + 1);
        bound = n;
    }

    void upload(int video)
    {
        videos[video] = true;
        while (curr <= bound && videos[curr])
        {
            curr++;
        }
    }

    int longest()
    {
        return curr - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
// @lc code=end
