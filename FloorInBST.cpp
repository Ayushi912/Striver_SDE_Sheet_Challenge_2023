#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int floorInBST(TreeNode<int> * root, int X)
{
    auto curr = root;
    int ans = -1;
    
    while(curr) {
        if(curr -> val > X) {
            curr = curr -> left;
        } else {
            ans = curr -> val;
            curr = curr -> right;
        }
    }
    
    return ans;
}
