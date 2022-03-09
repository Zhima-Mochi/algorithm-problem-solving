/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque
{
    int *arr;
    int head = 0;
    int tail = 0;
    int count = 0;
    int max_count;

public:
    MyCircularDeque(int k)
    {
        arr = new int[k];
        max_count = k;
    }

    bool insertFront(int value)
    {
        if (count == max_count)
        {
            return false;
        }
        if (count == 0)
        {
            arr[head] = value;
        }
        else
        {
            --head;
            head = (head + max_count) % max_count;
            arr[head] = value;
        }
        ++count;
        return true;
    }

    bool insertLast(int value)
    {
        if (count == max_count)
        {
            return false;
        }
        if (count == 0)
        {
            arr[tail] = value;
        }
        else
        {
            ++tail;
            tail %= max_count;
            arr[tail] = value;
        }
        ++count;
        return true;
    }

    bool deleteFront()
    {
        if (count == 0)
        {
            return false;
        }
        else if (count != 1)
        {
            head += 1;
            head %= max_count;
        }
        --count;
        return true;
    }

    bool deleteLast()
    {
        if (count == 0)
        {
            return false;
        }
        else if (count != 1)
        {
            tail -= 1;
            tail += max_count;
            tail %= max_count;
        }
        --count;
        return true;
    }

    int getFront()
    {
        if (count == 0)
        {
            return -1;
        }
        return arr[head];
    }

    int getRear()
    {
        if (count == 0)
        {
            return -1;
        }
        return arr[tail];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == max_count;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
