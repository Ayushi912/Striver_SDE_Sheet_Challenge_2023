#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int isBalanced(BinaryTreeNode<int>* root,bool &value){
   if(root==NULL)
       return 0;
   int left = isBalanced(root->left,value);
   int right = isBalanced(root->right,value);
   if(abs(left-right)>1)
       value = false;
   return max(left,right) + 1;    
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
   // Write your code here.
   bool value = true;
   isBalanced(root,value);
   return value;
}
