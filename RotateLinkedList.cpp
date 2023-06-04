/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head || !head->next || k==0) return head;
        Node* cur = head;
        int len=1;
        while(cur->next && ++len){
            cur= cur->next;
        }
        cur->next= head;
        k = k % len;
        k = len - k;
        while(k--){
            cur = cur->next;
        }
        head = cur->next;
        cur->next = NULL;
        return head;
}
