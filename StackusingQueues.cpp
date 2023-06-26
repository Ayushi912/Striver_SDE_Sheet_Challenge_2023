#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q;
public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        int sz = q.size();
        q.push(element);
        while(sz--)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty())
            return -1;
        int data = q.front();
        q.pop();
        return data;
    }

    int top() {
        // Implement the top() function.
       if(isEmpty())
            return -1;
        int data = q.front();
        return data;
    }
};
