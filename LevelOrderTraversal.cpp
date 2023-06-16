#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>v;
    queue<BinaryTreeNode<int>*>q;
     if(root==NULL){
         return v;
     }
    q.push(root);
   
  //  v.push_back(root->val);
    while(!q.empty()){
        BinaryTreeNode<int> *fro=q.front();
        q.pop();
        v.push_back(fro->val);
        if(fro->left!=NULL){
            q.push(fro->left);
        }
        if(fro->right!=NULL){
            q.push(fro->right);
        }
    }
    return v;
}
