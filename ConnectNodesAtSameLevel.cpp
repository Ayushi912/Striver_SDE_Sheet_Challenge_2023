#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        BinaryTreeNode<int> *prev = NULL;

        for (int i = 0; i < size; i++) {
            BinaryTreeNode<int> *current = q.front();
            q.pop();

            if (prev != NULL)
                prev->next = current;

            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);

            prev = current;
        }
    }
}
