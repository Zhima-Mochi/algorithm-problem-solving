/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

// @lc code=start
#define isBusyWait false
#if isBusyWait != true
//condition variable
class Foo
{
public:
    Foo()
    {
    }

    void first(function<void()> printFirst)
    {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++count;
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> lock(mtx);
        while (count != 1)
        {
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++count;
        cv.notify_all();
    }

    void
    third(function<void()> printThird)
    {
        unique_lock<mutex> lock(mtx);
        while (count != 2)
        {
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
    mutex mtx;
    condition_variable cv;
    int count = 0;
};
#else
class Foo
{
public:
    Foo()
    {
    }

    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        unique_lock<mutex> lock(mtx);
        ++count;
    }

    void second(function<void()> printSecond)
    {
        while (true)
        {
            unique_lock<mutex> lock(mtx);
            if (count == 1)
            {
                // printSecond() outputs "second". Do not change or remove this line.
                printSecond();
                ++count;
                break;
            }
        }
    }

    void third(function<void()> printThird)
    {
        while (true)
        {
            unique_lock<mutex> lock(mtx);
            if (count == 2)
            {
                // printThird() outputs "third". Do not change or remove this line.
                printThird();
                break;
            }
        }
    }
    mutex mtx;
    int count = 0;
};
#endif
// @lc code=end
