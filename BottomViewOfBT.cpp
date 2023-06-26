#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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
vector<int> bottomView(BinaryTreeNode<int> * root){
    // Write your code here.
    vector<int>res;
    if(!root) return res;
    map<int,int>mp;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(q.size())
    {
        auto p = q.front();
        q.pop();
        BinaryTreeNode<int> *curr = p.first;
        int level = p.second;
        mp[level] = curr->data;
        if(curr->left)
            q.push({curr->left,level-1});
        if(curr->right)
            q.push({curr->right,level+1});
    }
    for(auto i:mp)
        res.push_back(i.second);
    return res;
}
