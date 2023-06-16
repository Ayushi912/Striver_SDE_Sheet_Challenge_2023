#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>v;
    queue<TreeNode<int> *>q;
    q.push(root);
    if(root== NULL){
        return v;
    }
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
        TreeNode<int> * fro=q.front();
        q.pop();
        if(i==0){
            v.push_back(fro->data);
        }
        if(fro->left!=NULL){
            q.push(fro->left);
        }
         if(fro->right!=NULL){
            q.push(fro->right);
        }
        }

    }
    return v;
}
//time complexity:o(N);
//space complexity:o(height of binary tree)+0(n);
