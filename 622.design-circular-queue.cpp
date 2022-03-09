/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue
{
    int *circular_queue;
    int tail = 0;
    int head = 0;
    int num = 0;
    int max_size;

public:
    MyCircularQueue(int k)
    {
        circular_queue = new int[k];
        max_size = k;
    }

    bool enQueue(int value)
    {
        if (num == 0)
        {
            ++num;
            circular_queue[tail] = value;
            return true;
        }
        else if (num == max_size)
        {
            return false;
        }
        else
        {
            ++num;
            tail = (tail + 1) % max_size;
            circular_queue[tail] = value;
            return true;
        }
    }

    bool deQueue()
    {
        if (num == 0)
        {
            return false;
        }
        else if (num == 1)
        {
            --num;
            return true;
        }
        else
        {
            --num;
            head = (head + 1) % max_size;
            return true;
        }
    }

    int Front()
    {
        if (num == 0)
        {
            return -1;
        }
        else
        {
            return circular_queue[head];
        }
    }

    int Rear()
    {
        if (num == 0)
        {
            return -1;
        }
        else
        {
            return circular_queue[tail];
        }
    }

    bool isEmpty()
    {
        return num == 0;
    }

    bool isFull()
    {
        return num == max_size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
