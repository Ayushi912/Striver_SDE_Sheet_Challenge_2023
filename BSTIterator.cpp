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
#include<bits/stdc++.h>
class BSTiterator
{  
   stack<TreeNode<int>*>s;
public:
  void pushAll(TreeNode<int> * root){
      while(root!=NULL)
      {
          
          s.push(root);
          root = root->left;
      }
  }
   BSTiterator(TreeNode<int> *root)
   {
       // write your code her
       pushAll(root);
   }
   int next()
   {
       // write your code here
       TreeNode<int> * curr =s.top();
       s.pop();
       pushAll(curr->right);
       return curr->data;
   }
   bool hasNext()
   {
       // write your code here
       return !s.empty() ;
   }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
