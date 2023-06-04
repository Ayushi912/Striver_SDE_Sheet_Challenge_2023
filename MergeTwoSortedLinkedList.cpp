#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* list1, Node<int>* list2)
{
    // Write your code here.
    if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        Node<int>* ans = new Node<int>(0);
        Node<int>* tail = ans;
        while(list1 && list2){
            if(list1->data < list2->data){
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        if(list1 == NULL) tail->next= list2;
        else tail->next = list1;
        return ans->next;
}
