#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int to;
    int n;
    int *arr;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        n=capacity;
        to=-1;
    }

    void push(int num) {
        // Write your code here.
        if(to==n-1){
            return;
        }
        arr[++to]=num;
    }

    int pop() {
        // Write your code here.
        if(to!=-1){
        return arr[to--];

        }else {
            return -1;
        }
    }
    
    int top() {
        // Write your code here.
        if(to==-1){
        return -1;

        }else {
            return arr[to];
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(to==-1){
            return 1;
        }else{
            return 0;
        }
    }
    
    int isFull() {
        // Write your code here.
        if(to==n-1){
         return true;
     }else {
         return false;
     }
    }
    
};


