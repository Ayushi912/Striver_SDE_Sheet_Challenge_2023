#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return root;
    TreeNode<int>* originalRight=root->right;
    root->right=flattenBinaryTree(root->left);
    TreeNode<int>* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    temp->right=flattenBinaryTree(originalRight);
    root->left=NULL;
    return root;
}
