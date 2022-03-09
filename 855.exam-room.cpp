/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */
#include <vector>
using namespace std;
// @lc code=start
class ExamRoom
{
    int _n;
    vector<int> arr;

public:
    ExamRoom(int n)
    {
        _n = n;
    }

    int seat()
    {
        if (arr.empty())
        {
            arr.push_back(0);
            return 0;
        }
        else
        {
            int l = 0;
            int idx = 0;
            for (int i = 1, w = arr.size(); i != w; ++i)
            {
                if (l < (arr[i] - arr[i - 1]) / 2)
                {
                    l = (arr[i] - arr[i - 1]) / 2;
                    idx = i;
                }
            }
            if (arr[0] >= l && arr[0] >= _n - 1 - arr.back())
            {
                arr.insert(arr.begin(), 0);
                return 0;
            }
            else if (_n - 1 - arr.back() > l)
            {
                arr.push_back(_n - 1);
                return _n - 1;
            }
            else
            {
                int val = (arr[idx] + arr[idx - 1]) / 2;
                arr.insert(arr.begin() + idx, val);
                return val;
            }
        }
    }

    void leave(int p)
    {
        int idx = 0;
        for (auto &v : arr)
        {
            if (v == p)
            {
                break;
            }
            ++idx;
        }
        arr.erase(arr.begin() + idx);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end
