#include <stack>
class Queue {
    // Define the data members(if any) here.
    stack<int> st1,st2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        st1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        int data = peek();
        if(data == -1)
            return -1;
        st2.pop();
        return data;
    }

    int peek() {
        // Implement the peek() function here.
        if(isEmpty())
            return -1;
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(st1.empty() && st2.empty())
            return true;
        return false;
    }
};
