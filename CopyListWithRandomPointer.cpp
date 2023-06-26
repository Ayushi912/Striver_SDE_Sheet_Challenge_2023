#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head == nullptr)
        return head;
    LinkedListNode<int> *tmp = head;
    while(tmp != nullptr)
    {
        LinkedListNode<int> *node = new LinkedListNode<int>(tmp -> data);
        node -> next = tmp -> next;
        tmp -> next = node;
        tmp = node -> next;
    }
    tmp = head;
    while(tmp != nullptr)
    {
        tmp -> next -> random = tmp -> random == nullptr ? nullptr : tmp -> random -> next;
        tmp = tmp -> next -> next;
    }
    tmp = head;
    LinkedListNode<int> *ans = tmp -> next;
    while(tmp != nullptr)
    {
        LinkedListNode<int> *copy = tmp -> next;
        tmp -> next = copy -> next;
        copy -> next = tmp -> next == nullptr ? nullptr : tmp -> next -> next;
        tmp = tmp -> next;
    }
    return ans;

}
