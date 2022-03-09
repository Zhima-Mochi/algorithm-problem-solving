/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
#include <map>
#include <queue>
using namespace std;
// @lc code=start
// class MedianFinder
// {
// public:
//     /** initialize your data structure here. */
//     MedianFinder()
//     {
//     }

//     void addNum(int num)
//     {

//         if (num <= lower_equal_mp.begin()->first || lower_equal_size == 0)
//         {
//             ++lower_equal_mp[num];
//             ++lower_equal_size;
//             auto &val = lower_equal_mp.begin()->second;
//             if (lower_equal_size >= greater_size + 2 * val)
//             {
//                 greater_size += val;
//                 lower_equal_size -= val;
//                 greater_mp.insert(*(lower_equal_mp.begin()));
//                 lower_equal_mp.erase(lower_equal_mp.begin());
//             }
//         }
//         else
//         {
//             ++greater_mp[num];
//             ++greater_size;
//             if (lower_equal_size < greater_size)
//             {
//                 lower_equal_mp.insert(*(greater_mp.begin()));
//                 greater_mp.erase(greater_mp.begin());
//                 lower_equal_size += lower_equal_mp.begin()->second;
//                 greater_size -= lower_equal_mp.begin()->second;
//             }
//         }
//     }

//     double findMedian()
//     {
//         if (lower_equal_size != greater_size)
//         {
//             return lower_equal_mp.begin()->first;
//         }
//         else
//         {
//             return static_cast<double>(lower_equal_mp.begin()->first) / 2 + static_cast<double>(greater_mp.begin()->first) / 2;
//         }
//     }
//     map<int, short, greater<int>> lower_equal_mp;
//     map<int, short> greater_mp;
//     size_t lower_equal_size = 1;
//     size_t greater_size = 1;
// };

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        median_iter = mp.begin();
    }

    void addNum(int num)
    {
        ++mp[num];
        if (lower_equal_size == 0 || num <= median_iter->first)
        {
            ++lower_equal_size;
            auto &val = median_iter->second;
            if (lower_equal_size >= greater_size + 2 * val)
            {
                greater_size += val;
                lower_equal_size -= val;
                --median_iter;
            }
        }
        else
        {
            ++greater_size;
            if (lower_equal_size < greater_size)
            {
                ++median_iter;
                lower_equal_size += median_iter->second;
                greater_size -= median_iter->second;
            }
        }
    }

    double findMedian()
    {
        if (lower_equal_size != greater_size)
        {
            return median_iter->first;
        }
        else
        {
            return (static_cast<double>(median_iter->first) + static_cast<double>(next(median_iter)->first)) / 2;
        }
    }
    map<int, short> mp;
    map<int, short>::iterator median_iter;
    short lower_equal_size = 0;
    short greater_size = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
