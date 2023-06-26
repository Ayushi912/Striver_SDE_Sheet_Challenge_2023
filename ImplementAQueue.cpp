#include <bits/stdc++.h> 

class LinkedList{
public:
    int data;
    LinkedList *next;

    LinkedList(int data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};

class Queue {
public:
    LinkedList *fr, *rr;
    Queue() {
        // Implement the Constructor
        fr = nullptr;
        rr = nullptr;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(fr == nullptr)
            return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rr == nullptr)
        {
            rr = new LinkedList(data);
            fr = rr;
        }
        else
        {
            rr -> next = new LinkedList(data);
            rr = rr -> next;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())
            return -1;
        int data = fr -> data;
        LinkedList *tmp = fr;
        if(fr == rr)
            fr = rr = nullptr;
        else
            fr = fr -> next;
        delete(tmp);
        return data;
    }

    int front() {
        // Implement the fr() function
        if(isEmpty())
            return -1;
        return fr -> data;
    }
};
